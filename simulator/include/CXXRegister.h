////////////////////////////////////////////////////////////////////////////////
///
/// @file       CXXRegister.h
///
/// @project
///
/// @brief      C++ REgister wrapper code
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2018, Evan Lojewski
/// @cond
///
/// All rights reserved.
///
/// Redistribution and use in source and binary forms, with or without
/// modification, are permitted provided that the following conditions are met:
/// 1. Redistributions of source code must retain the above copyright notice,
/// this list of conditions and the following disclaimer.
/// 2. Redistributions in binary form must reproduce the above copyright notice,
/// this list of conditions and the following disclaimer in the documentation
/// and/or other materials provided with the distribution.
/// 3. Neither the name of the copyright holder nor the
/// names of its contributors may be used to endorse or promote products
/// derived from this software without specific prior written permission.
///
////////////////////////////////////////////////////////////////////////////////
///
/// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
/// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
/// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
/// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
/// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
/// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
/// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
/// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
/// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
/// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
/// POSSIBILITY OF SUCH DAMAGE.
/// @endcond
////////////////////////////////////////////////////////////////////////////////
#ifndef CXX_REGISTER_H
#define CXX_REGISTER_H

#include <iomanip> // std::setw
#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#include <list>

class CXXRegisterBase
{
private:
    std::list<std::pair<int, const char*>> mEnums;
public:
    CXXRegisterBase(unsigned int offset, unsigned int width)
    {
        mName = NULL;
        mComponentOffset = 0;
        mMask = 0;
        mBaseRegister = NULL;
        mBitWidth = width;
        mBitPosition = offset;
        for (unsigned int i = offset; i < offset + width; i++)
        {
            mMask |= 1u << i;
        }
    }

    virtual void setBaseRegister(CXXRegisterBase *base)
    {
        // assert(base != NULL, "Base must not be null");

        mBaseRegister = base;
        base->addRelatedRegister(this);
    }

    void setName(const char *name)
    {
        if(name)
        {
            mName = name;
        }
    }

    const char* getEnum(int value)
    {
        std::list<std::pair<int, const char*>>::iterator it;
        for (it = mEnums.begin(); it != mEnums.end();
             it++)
        {
            if(value == (*it).first)
            {
                return (*it).second;
            }
        }
        return NULL;
    }

    void addEnum(const char* name, int value)
    {
        if(!getEnum(value))
        {
            mEnums.push_back(std::make_pair(value, name));
        }
    }

    const char *getName(void)
    {
        if(!mName)
        {
            return "(undefined)";
        }
        else
        {
            return mName;
        }
    }

    void setComponentOffset(unsigned int offset)
    {
        mComponentOffset = offset;
    }

    unsigned int getComponentOffset(void)
    {
        return mComponentOffset;
    }

    void print(unsigned int value, int indent = false)
    {
        const char* name = mName;
        char addr_str[16];

        if(!name)
        {
            snprintf(addr_str, sizeof(addr_str), "0x%X", mComponentOffset);
            name = addr_str;
        }

        unsigned int masked = (value & mMask) >> mBitPosition;
        const char* enumstr = getEnum(masked);
        std::ios::fmtflags fmt(std::cout.flags());

        if (indent)
        {
            std::cout << std::right << std::setw(35) << name << ": 0x"
                      << std::hex << masked;
        }
        else
        {
            std::cout << std::endl
                      << std::left << std::setw(36) << name << " 0x"
                      << std::hex << masked;
        }

        std::cout.flags(fmt);

        if(enumstr)
        {
            std::cout << " (" << enumstr << ")";
        }

        std::cout << std::endl;
    }

    void printAll(unsigned int value)
    {
        std::vector<CXXRegisterBase *>::iterator it;
        for (it = mRelatedRegisters.begin(); it != mRelatedRegisters.end();
             it++)
        {
            (*it)->print(value, true);
        }
    }

protected:
    unsigned int mComponentOffset;
    unsigned int mBitPosition;
    unsigned int mBitWidth;
    unsigned int mMask;
    const char *mName;

    std::vector<CXXRegisterBase *> mRelatedRegisters;

    // This is the main controller register
    CXXRegisterBase *mBaseRegister;

    virtual void addRelatedRegister(CXXRegisterBase *related)
    {
        mRelatedRegisters.push_back(related);
    }

    // Virtual, must be re-implemented by subclasses
    virtual void doWriteCallbacks(void) = 0;
    virtual void doReadCallbacks(void) = 0;

    virtual unsigned int getRawValue(void) = 0;
    virtual unsigned int getTempValue(void) = 0;
    virtual void setRawValue(unsigned int) = 0;
    virtual void setTempValue(unsigned int) = 0;

    void doRelatedWritesBase(CXXRegisterBase *source)
    {
        if (source->mMask != this->mMask)
        {
            // read latest value as we are only modifying some bits.
            doReadCallbacks();
            setRawValue(getTempValue());
        }

        // Update base temp value with latest write.
        unsigned int base = getRawValue();
        base &= ~(source->mMask);
        unsigned int tempValue = base | source->getRawValue();
        // printf("Updating base from %x & %x to %x (new write: %x)\n",
        // getRawValue(), ~source->mMask, tempValue, source->getRawValue());
        setTempValue(tempValue);

        // Call the write callbacks. This may update the raw value as needed.
        if (this != source)
        {
            doWriteCallbacks();
        }
    }

    void doRelatedWrites()
    {
        // printf("doRelatedWrites on %p\n", this);
        // Call doRelatedWrites on the base register.
        if (mBaseRegister)
        {
            mBaseRegister->doRelatedWritesBase(this);
        }
        else
        {
            // we are the base
            doRelatedWritesBase(this);
        }
    }

    void doRelatedReadsBase(CXXRegisterBase *source)
    {
        // Read the latest from the base register.
        doReadCallbacks();
        unsigned int readValue = getTempValue();

        // Update chained registers.
        std::vector<CXXRegisterBase *>::iterator it;
        for (it = mRelatedRegisters.begin(); it != mRelatedRegisters.end();
             it++)
        {
            // Update chained registers with latest data from base register.
            (*it)->setRawValue(readValue);
            // Update the temp value for all registers.
            (*it)->doReadCallbacks();

            // FIXME: handle updated from chained registers?
        }

        setRawValue(readValue);
    }

    void doRelatedReads()
    {
        // Call doRelatedReads on the base register.
        if (mBaseRegister)
        {
            mBaseRegister->doRelatedReadsBase(this);
        }
        else
        {
            // printf("Calling callbacks...\n");
            doReadCallbacks();
        }
    }
};

template<typename T, unsigned int OFFSET, unsigned int WIDTH>
class CXXRegister : public CXXRegisterBase
{
private:
    typedef T (*callback_t)(T val, unsigned int, void *);
    std::vector<std::pair<callback_t, void *>> mReadCallback;
    std::vector<std::pair<callback_t, void *>> mWriteCallback;

    T mValue;
    T mTempValue;

    virtual void doWriteCallbacks(void)
    {
        T val = mTempValue;
        // call callbacks
        typename std::vector<std::pair<callback_t, void *>>::iterator it;
        for (it = mWriteCallback.begin(); it != mWriteCallback.end(); it++)
        {
            callback_t callback;
            callback = (*it).first;
            if (callback)
            {
                val = callback(val, mComponentOffset, (*it).second);
            }
        }
        mValue = val;
    }

    virtual void doReadCallbacks(void)
    {
        // call callbacks
        T val = mValue;
        typename std::vector<std::pair<callback_t, void *>>::iterator it;
        for (it = mReadCallback.begin(); it != mReadCallback.end(); it++)
        {
            callback_t callback;
            callback = (*it).first;
            if (callback)
            {
                val = callback(val, mComponentOffset, (*it).second);
            }
        }

        mTempValue = val;
    }

    void doWrite(T val)
    {
        // printf("doWrite on %p with %x.\n", this, val);
        mTempValue = val;
        doWriteCallbacks();
        doRelatedWrites();
    }

    T doRead(void)
    {
        // printf("doRead on %p.\n", this);

        doRelatedReads();
        return mTempValue;
    }

    virtual unsigned int getRawValue(void)
    {
        // printf("Getting raw: 0x%x\n", (mValue << mBitPosition) & mMask);
        return (mValue << mBitPosition) & mMask;
    }

    virtual void setRawValue(unsigned int newVal)
    {
        // printf("Setting raw: 0x%x\n", (newVal & mMask) >> mBitPosition);
        mValue = (newVal & mMask) >> mBitPosition;
    }

    virtual unsigned int getTempValue(void)
    {
        // printf("Getting temp: 0x%x\n", (mTempValue << mBitPosition) & mMask);
        return (mTempValue << mBitPosition) & mMask;
    }

    virtual void setTempValue(unsigned int newVal)
    {
        // printf("Setting temp: 0x%x (%x)\n", (newVal & mMask) >> mBitPosition,
        // newVal);
        mTempValue = (newVal & mMask) >> mBitPosition;
    }

public:
    CXXRegister() : CXXRegisterBase(OFFSET, WIDTH), mValue(0), mTempValue(0)
    {
    }

    CXXRegister(T val) : CXXRegisterBase(OFFSET, WIDTH), mValue(val), mTempValue(0)
    {
        // Manually instantiated. FIXME.
    }

    void installReadCallback(callback_t callback, void *args)
    {
        mReadCallback.push_back(std::make_pair(callback, args));
    }

    void installWriteCallback(callback_t callback, void *args)
    {
        mWriteCallback.push_back(std::make_pair(callback, args));
    }

    virtual ~CXXRegister()
    {
    }

    void print(void)
    {
        T value = doRead();
        CXXRegisterBase::print(value);
        CXXRegisterBase::printAll(value);
    }

    T getValue()
    {
        return mValue;
    }

    void setValue(T val)
    {
        mValue = val & mMask;
    }

    T operator=(T val)
    {
        //  Write
        doWrite(val);
        return mValue;
    }

    T operator=(CXXRegister<T, OFFSET, WIDTH> val)
    {
        //  Write
        doWrite((T)val);
        return mValue;
    }

    operator T()
    {
        // Read
        return doRead();
    }

    T operator+=(T val)
    {
        // Read - sub - Write
        return this->operator=(operator T() + val);
    }

    T operator++(void)
    {
        // Read - add - Write
        return this->operator=(operator T() + 1);
    }

    T operator-=(T val)
    {
        // Read - sub - Write
        return this->operator=(operator T() - val);
    }

    T operator--(void)
    {
        // Read - sub - Write
        return this->operator=(operator T() - 1);
    }

    T operator*=(T val)
    {
        // Read - mul - Write
        return this->operator=(operator T() * val);
    }

    T operator/=(T val)
    {
        // Read - div - Write
        return this->operator=(operator T() / val);
    }

    T operator<<=(T val)
    {
        // Read - left shift - Write
        return this->operator=(operator T() << val);
    }

    T operator>>=(T val)
    {
        // Read - right shift - Write
        return this->operator=(operator T() >> val);
    }

    T operator|=(T val)
    {
        // Read - or - Write
        return this->operator=(operator T() | val);
    }

    T operator&=(T val)
    {
        // Read - and - Write
        return this->operator=(operator T() & val);
    }

    T operator^=(T val)
    {
        // Read - xor - Write
        return this->operator=(operator T() ^ val);
    }

protected:
};

#endif /* CXX_REGISTER_H */