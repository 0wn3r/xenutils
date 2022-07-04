.section .kernel_domu,"a"

/* DomU binary from include/ dir */
.incbin		"domain_bins/uImage.bin"

.section .dtb_domu,"a"

/* DomU dtb from include/ dir */
.incbin		"domain_bins/uboot_minimal.dtb"
