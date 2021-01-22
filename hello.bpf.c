// +build ignore

/* In Linux 5.4 asm_inline was introduced, but it's not supported by clang.
 * Redefine it to just asm to enable successful compilation.
 * see https://github.com/iovisor/bcc/commit/2d1497cde1cc9835f759a707b42dea83bee378b8 for more details
 */
#include <linux/types.h>
#ifdef asm_inline
#undef asm_inline
#define asm_inline asm
#endif

#include <linux/bpf.h>
#include <bpf_helpers.h>

char LICENSE[] SEC("license") = "Dual BSD/GPL";

SEC("kprobe/sys_execve")
int hello(void *ctx) {
    bpf_printk("I'm alive!");
    return 0;
}