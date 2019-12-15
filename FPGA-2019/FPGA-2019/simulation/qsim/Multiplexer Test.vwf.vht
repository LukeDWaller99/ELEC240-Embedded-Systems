-- Copyright (C) 2018  Intel Corporation. All rights reserved.
-- Your use of Intel Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Intel Program License 
-- Subscription Agreement, the Intel Quartus Prime License Agreement,
-- the Intel FPGA IP License Agreement, or other applicable license
-- agreement, including, without limitation, that your use is for
-- the sole purpose of programming logic devices manufactured by
-- Intel and sold by Intel or its authorized distributors.  Please
-- refer to the applicable agreement for further details.

-- *****************************************************************************
-- This file contains a Vhdl test bench with test vectors .The test vectors     
-- are exported from a vector file in the Quartus Waveform Editor and apply to  
-- the top level entity of the current Quartus project .The user can use this   
-- testbench to simulate his design using a third-party simulation tool .       
-- *****************************************************************************
-- Generated on "12/15/2019 20:29:44"
                                                             
-- Vhdl Test Bench(with test vectors) for design  :          multiplexer
-- 
-- Simulation tool : 3rd Party
-- 

LIBRARY ieee;                                               
USE ieee.std_logic_1164.all;                                

ENTITY multiplexer_vhd_vec_tst IS
END multiplexer_vhd_vec_tst;
ARCHITECTURE multiplexer_arch OF multiplexer_vhd_vec_tst IS
-- constants                                                 
-- signals                                                   
SIGNAL Input : STD_LOGIC_VECTOR(3 DOWNTO 0);
SIGNAL led_flash : STD_LOGIC;
SIGNAL Output : STD_LOGIC_VECTOR(7 DOWNTO 0);
SIGNAL packet_selector : STD_LOGIC;
COMPONENT multiplexer
	PORT (
	Input : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
	led_flash : IN STD_LOGIC;
	Output : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
	packet_selector : IN STD_LOGIC
	);
END COMPONENT;
BEGIN
	i1 : multiplexer
	PORT MAP (
-- list connections between master ports and signals
	Input => Input,
	led_flash => led_flash,
	Output => Output,
	packet_selector => packet_selector
	);
-- Input[3]
t_prcs_Input_3: PROCESS
BEGIN
	Input(3) <= '1';
	WAIT FOR 5000 ps;
	FOR i IN 1 TO 99
	LOOP
		Input(3) <= '0';
		WAIT FOR 5000 ps;
		Input(3) <= '1';
		WAIT FOR 5000 ps;
	END LOOP;
	Input(3) <= '0';
WAIT;
END PROCESS t_prcs_Input_3;
-- Input[2]
t_prcs_Input_2: PROCESS
BEGIN
	Input(2) <= '0';
WAIT;
END PROCESS t_prcs_Input_2;
-- Input[1]
t_prcs_Input_1: PROCESS
BEGIN
	Input(1) <= '0';
WAIT;
END PROCESS t_prcs_Input_1;
-- Input[0]
t_prcs_Input_0: PROCESS
BEGIN
	Input(0) <= '0';
WAIT;
END PROCESS t_prcs_Input_0;

-- packet_selector
t_prcs_packet_selector: PROCESS
BEGIN
	packet_selector <= '0';
WAIT;
END PROCESS t_prcs_packet_selector;

-- led_flash
t_prcs_led_flash: PROCESS
BEGIN
LOOP
	led_flash <= '0';
	WAIT FOR 10000 ps;
	led_flash <= '1';
	WAIT FOR 10000 ps;
	IF (NOW >= 1000000 ps) THEN WAIT; END IF;
END LOOP;
END PROCESS t_prcs_led_flash;
END multiplexer_arch;
