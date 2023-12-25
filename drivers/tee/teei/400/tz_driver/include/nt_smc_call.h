/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2015-2019, MICROTRUST Incorporated
 * All Rights Reserved.
 *
 */

#ifndef SMC_CALL_H_
#define SMC_CALL_H_

#include <teei_secure_api.h>
#include <linux/arm-smccc.h>

/*This field id is fixed by arm*/
#define ID_FIELD_F_FAST_SMC_CALL		1
#define ID_FIELD_F_STANDARD_SMC_CALL		0
#define ID_FIELD_W_64				1
#define ID_FIELD_W_32				0

#define ID_FIELD_T_ARM_SERVICE			0
#define ID_FIELD_T_CPU_SERVICE			1
#define ID_FIELD_T_SIP_SERVICE			2
#define ID_FIELD_T_OEM_SERVICE			3
#define ID_FIELD_T_STANDARD_SERVICE		4
/*TA Call 48-49*/
#define ID_FIELD_T_TA_SERVICE0			48
#define ID_FIELD_T_TA_SERVICE1			49
/*TOS Call 50-63*/
#define ID_FIELD_T_TRUSTED_OS_SERVICE0		50
#define ID_FIELD_T_TRUSTED_OS_SERVICE1		51
#define ID_FIELD_T_TRUSTED_OS_SERVICE2		52
#define ID_FIELD_T_TRUSTED_OS_SERVICE3		53

#define MAKE_SMC_CALL_ID(F, W, T, FN) (((F)<<31)|((W)<<30)|((T)<<24)|(FN))

#define SMC_CALL_RTC_OK                 0x0
#define SMC_CALL_RTC_UNKNOWN_FUN        0xFFFFFFFF
#define SMC_CALL_RTC_MONITOR_NOT_READY  0xFFFFFFFE

#define SMC_CALL_INTERRUPTED_IRQ	0x54
#define SMC_CALL_DONE			0x45

#define N_GET_T_FP_DEVICE_ID     \
		MAKE_SMC_CALL_ID(ID_FIELD_F_FAST_SMC_CALL, \
		ID_FIELD_W_64, ID_FIELD_T_TRUSTED_OS_SERVICE2, 11)
/*Child type command type for soter to recognize*/
#define N_ACK_T_INVOKE_DRV_CMD	\
		MAKE_SMC_CALL_ID(ID_FIELD_F_STANDARD_SMC_CALL, \
		ID_FIELD_W_64, ID_FIELD_T_TRUSTED_OS_SERVICE3, 5)
#define N_INVOKE_T_LOAD_TEE_CMD	\
		MAKE_SMC_CALL_ID(ID_FIELD_F_STANDARD_SMC_CALL, \
		ID_FIELD_W_64, ID_FIELD_T_TRUSTED_OS_SERVICE3, 6)
#define N_INVOKE_T_NQ_CMD		\
		MAKE_SMC_CALL_ID(ID_FIELD_F_STANDARD_SMC_CALL, \
		ID_FIELD_W_64, ID_FIELD_T_TRUSTED_OS_SERVICE3, 2)

/*For non-secure side Fast Call*/
#define N_SWITCH_TO_T_OS_STAGE2	\
		MAKE_SMC_CALL_ID(ID_FIELD_F_FAST_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE2, 0)
#define N_GET_PARAM_IN		\
		MAKE_SMC_CALL_ID(ID_FIELD_F_FAST_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE2, 1)
#define N_INIT_T_FC_BUF	\
		MAKE_SMC_CALL_ID(ID_FIELD_F_FAST_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE2, 2)
#define N_INVOKE_T_FAST_CALL	\
		MAKE_SMC_CALL_ID(ID_FIELD_F_FAST_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE2, 3)
#define NT_DUMP_STATE		\
		MAKE_SMC_CALL_ID(ID_FIELD_F_FAST_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE2, 4)
#define N_ACK_T_FOREGROUND	\
		MAKE_SMC_CALL_ID(ID_FIELD_F_FAST_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE2, 5)
#define N_ACK_T_BACKSTAGE	\
		MAKE_SMC_CALL_ID(ID_FIELD_F_FAST_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE2, 6)
#define N_INIT_T_BOOT_STAGE1	\
		MAKE_SMC_CALL_ID(ID_FIELD_F_FAST_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE2, 7)
#define N_SWITCH_CORE \
		MAKE_SMC_CALL_ID(ID_FIELD_F_FAST_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE2, 8)
#define N_GET_NON_IRQ_NUM      \
		MAKE_SMC_CALL_ID(ID_FIELD_F_FAST_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE2, 9)
#define N_GET_SE_OS_STATE    \
		MAKE_SMC_CALL_ID(ID_FIELD_F_FAST_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE2, 10)
#define N_GET_T_FP_DEVICE_ID_32     \
		MAKE_SMC_CALL_ID(ID_FIELD_F_FAST_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE2, 11)
#define N_ADD_TRIGGER_IRQ_COUNT		\
		MAKE_SMC_CALL_ID(ID_FIELD_F_FAST_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE2, 12)
#define N_GET_RESERVED_MEM_SIZE         \
		MAKE_SMC_CALL_ID(ID_FIELD_F_FAST_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE2, 13)
#define N_GET_RESERVED_MEM_PADDR        \
		MAKE_SMC_CALL_ID(ID_FIELD_F_FAST_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE2, 14)

/*For non-secure side Standard Call*/
#define NT_SCHED_T		\
		MAKE_SMC_CALL_ID(ID_FIELD_F_STANDARD_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE3, 0)
#define N_INVOKE_T_SYS_CTL	\
		MAKE_SMC_CALL_ID(ID_FIELD_F_STANDARD_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE3, 1)
#define N_INVOKE_T_NQ		\
		MAKE_SMC_CALL_ID(ID_FIELD_F_STANDARD_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE3, 2)
#define N_INVOKE_T_DRV		\
		MAKE_SMC_CALL_ID(ID_FIELD_F_STANDARD_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE3, 3)
#define N_RAISE_T_EVENT		\
		MAKE_SMC_CALL_ID(ID_FIELD_F_STANDARD_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE3, 4)
#define N_ACK_T_INVOKE_DRV	\
		MAKE_SMC_CALL_ID(ID_FIELD_F_STANDARD_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE3, 5)
#define N_INVOKE_T_LOAD_TEE	\
		MAKE_SMC_CALL_ID(ID_FIELD_F_STANDARD_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE3, 6)
#define N_ACK_T_LOAD_IMG	\
		MAKE_SMC_CALL_ID(ID_FIELD_F_STANDARD_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE3, 7)
#define NT_SCHED_T_FIQ	\
		MAKE_SMC_CALL_ID(ID_FIELD_F_STANDARD_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE3, 8)
#define NT_CANCEL_T_TUI	\
		MAKE_SMC_CALL_ID(ID_FIELD_F_STANDARD_SMC_CALL, \
		ID_FIELD_W_32, ID_FIELD_T_TRUSTED_OS_SERVICE3, 9)

static inline void get_t_device_id(uint64_t *p0)
{
	struct arm_smccc_res res;

	arm_smccc_smc(N_GET_T_FP_DEVICE_ID_32, 0, 0, 0,
			0, 0, 0, 0, &res);
	*p0 = res.a0;
}
#endif /* SMC_CALL_H_ */
