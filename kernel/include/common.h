/**
 * @file common.h
 * @author Пиминов Никита (nikita.piminoff@yandex.ru)
 * @brief Основные определения ядра
 * @version 0.3.3
 * @date 2023-12-07
 * @copyright Copyright SayoriOS Team (c) 2022-2023
 */
#pragma once

#define		FALSE			0
#define		TRUE			1

#ifndef __cplusplus

typedef enum {
    false = 0,
    true = 1
} bool;

#define nullptr ((void*)0)
#define NULL (0)

#endif

#define ALIGN(value, align) ((value) + ((-(value)) & ((align) - 1)))

/* 64-bit types */
typedef	unsigned long long	uint64_t;
typedef	long long			int64_t;
/* 32-bit types */
typedef	unsigned int	uint32_t;
typedef	int		int32_t;
/* 16-bit types */
typedef	unsigned short	uint16_t;
typedef	short		int16_t;
/* 8-bit types */
typedef	unsigned char	uint8_t;
typedef	char		int8_t;

typedef	uint32_t		size_t;
typedef	int32_t			ssize_t;

struct registers {
    uint32_t	ds;
    uint32_t	edi, esi, ebp, esp, ebx, edx, ecx, eax;
    uint32_t	int_num, err_code;
    uint32_t	eip, cs, eflags, useresp, ss;
} __attribute__((packed));

typedef	struct	registers	registers_t;

// Use ON_NULLPTR macro to tell a user (developer) that he passed a nullptr
#define ON_NULLPTR(ptr, code) do { if((ptr) == 0) { \
		qemu_err("Mumble, you have an illusion that you see an object but you can't touch it because it's not exist..."); \
		code                                               \
	}      \
} while(0)
