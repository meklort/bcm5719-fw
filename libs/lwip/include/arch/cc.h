

#ifndef ARCH_CC_H
#define ARCH_CC_H

#define LWIP_PLATFORM_DIAG(x)
#define LWIP_PLATFORM_ASSERT(x)    do { for(;;) {} } while(0)

#define LWIP_NO_INTTYPES_H 1
#define LWIP_NO_CTYPE_H 1

#define LWIP_PROVIDE_ERRNO 1

#endif /* ARCH_CC_H */
