transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vcom -93 -work work {C:/git/ELEC240/Coursework/FPGA-2019/MyClockDivider.vhd}

