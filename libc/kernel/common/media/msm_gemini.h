/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef __LINUX_MSM_GEMINI_H
#define __LINUX_MSM_GEMINI_H

#include <linux/types.h>
#include <asm/sizes.h>
#include <linux/ioctl.h>

#define MSM_GMN_IOCTL_MAGIC 'g'

#define MSM_GMN_IOCTL_GET_HW_VERSION   _IOW(MSM_GMN_IOCTL_MAGIC, 1, struct msm_gemini_hw_cmd *)

#define MSM_GMN_IOCTL_RESET   _IOW(MSM_GMN_IOCTL_MAGIC, 2, struct msm_gemini_ctrl_cmd *)

#define MSM_GMN_IOCTL_STOP   _IOW(MSM_GMN_IOCTL_MAGIC, 3, struct msm_gemini_hw_cmds *)

#define MSM_GMN_IOCTL_START   _IOW(MSM_GMN_IOCTL_MAGIC, 4, struct msm_gemini_hw_cmds *)

#define MSM_GMN_IOCTL_INPUT_BUF_ENQUEUE   _IOW(MSM_GMN_IOCTL_MAGIC, 5, struct msm_gemini_buf *)

#define MSM_GMN_IOCTL_INPUT_GET   _IOW(MSM_GMN_IOCTL_MAGIC, 6, struct msm_gemini_buf *)

#define MSM_GMN_IOCTL_INPUT_GET_UNBLOCK   _IOW(MSM_GMN_IOCTL_MAGIC, 7, int)

#define MSM_GMN_IOCTL_OUTPUT_BUF_ENQUEUE   _IOW(MSM_GMN_IOCTL_MAGIC, 8, struct msm_gemini_buf *)

#define MSM_GMN_IOCTL_OUTPUT_GET   _IOW(MSM_GMN_IOCTL_MAGIC, 9, struct msm_gemini_buf *)

#define MSM_GMN_IOCTL_OUTPUT_GET_UNBLOCK   _IOW(MSM_GMN_IOCTL_MAGIC, 10, int)

#define MSM_GMN_IOCTL_EVT_GET   _IOW(MSM_GMN_IOCTL_MAGIC, 11, struct msm_gemini_ctrl_cmd *)

#define MSM_GMN_IOCTL_EVT_GET_UNBLOCK   _IOW(MSM_GMN_IOCTL_MAGIC, 12, int)

#define MSM_GMN_IOCTL_HW_CMD   _IOW(MSM_GMN_IOCTL_MAGIC, 13, struct msm_gemini_hw_cmd *)

#define MSM_GMN_IOCTL_HW_CMDS   _IOW(MSM_GMN_IOCTL_MAGIC, 14, struct msm_gemini_hw_cmds *)

#define MSM_GMN_IOCTL_TEST_DUMP_REGION   _IOW(MSM_GMN_IOCTL_MAGIC, 15, unsigned long)

#define MSM_GEMINI_MODE_REALTIME_ENCODE 0
#define MSM_GEMINI_MODE_OFFLINE_ENCODE 1
#define MSM_GEMINI_MODE_REALTIME_ROTATION 2
#define MSM_GEMINI_MODE_OFFLINE_ROTATION 3
struct msm_gemini_ctrl_cmd {
 uint32_t type;
 uint32_t len;
 void *value;
};

#define MSM_GEMINI_EVT_RESET 0
#define MSM_GEMINI_EVT_FRAMEDONE 1
#define MSM_GEMINI_EVT_ERR 2

struct msm_gemini_buf {
 uint32_t type;
 int fd;

 void *vaddr;

 uint32_t y_off;
 uint32_t y_len;
 uint32_t framedone_len;

 uint32_t cbcr_off;
 uint32_t cbcr_len;

 uint32_t num_of_mcu_rows;
};

#define MSM_GEMINI_HW_CMD_TYPE_READ 0
#define MSM_GEMINI_HW_CMD_TYPE_WRITE 1
#define MSM_GEMINI_HW_CMD_TYPE_WRITE_OR 2
#define MSM_GEMINI_HW_CMD_TYPE_UWAIT 3
#define MSM_GEMINI_HW_CMD_TYPE_MWAIT 4
#define MSM_GEMINI_HW_CMD_TYPE_MDELAY 5
#define MSM_GEMINI_HW_CMD_TYPE_UDELAY 6
struct msm_gemini_hw_cmd {

 uint32_t type:4;

 uint32_t n:12;
 uint32_t offset:16;
 uint32_t mask;
 union {
 uint32_t data;
 uint32_t *pdata;
 };
};

struct msm_gemini_hw_cmds {
 uint32_t m;
 struct msm_gemini_hw_cmd hw_cmd[1];
};

#endif
