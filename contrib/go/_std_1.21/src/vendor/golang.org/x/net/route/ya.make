GO_LIBRARY()
IF (OS_DARWIN AND ARCH_ARM64)
    SRCS(
		address.go
		binary.go
		empty.s
		interface.go
		interface_classic.go
		interface_multicast.go
		message.go
		route.go
		route_classic.go
		sys.go
		sys_darwin.go
		syscall.go
		zsys_darwin.go
    )
ELSEIF (OS_DARWIN AND ARCH_X86_64)
    SRCS(
		address.go
		binary.go
		empty.s
		interface.go
		interface_classic.go
		interface_multicast.go
		message.go
		route.go
		route_classic.go
		sys.go
		sys_darwin.go
		syscall.go
		zsys_darwin.go
    )
ENDIF()
END()
