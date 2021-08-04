

#ifndef ARCH_CC_H
#define ARCH_CC_H

#define LWIP_PLATFORM_DIAG(x)

#ifndef LWIP_PLATFORM_ASSERT
#define LWIP_PLATFORM_ASSERT(x) do {printf(__FILE__ "ASSERT %d\n", __LINE__); for (;;) {} } while (0)
#endif /* LWIP_PLATFORM_ASSERT */

#define LWIP_NO_INTTYPES_H 1
#define LWIP_NO_CTYPE_H 1

#define LWIP_PROVIDE_ERRNO 1

#endif /* ARCH_CC_H */
