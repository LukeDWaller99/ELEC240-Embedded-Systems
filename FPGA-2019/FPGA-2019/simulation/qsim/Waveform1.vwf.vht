-- Copyright (C) 2019  Intel Corporation. All rights reserved.
-- Your use of Intel Corporation's design tools, logic functions 
-- and other software and tools, and any partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Intel Program License 
-- Subscription Agreement, the Intel Quartus Prime License Agreement,
-- the Intel FPGA IP License Agreement, or other applicable license
-- agreement, including, without limitation, that your use is for
-- the sole purpose of programming logic devices manufactured by
-- Intel and sold by Intel or its authorized distributors.  Please
-- refer to the applicable agreement for further details, at
-- https://fpgasoftware.intel.com/eula.

-- *****************************************************************************
-- This file contains a Vhdl test bench with test vectors .The test vectors     
-- are exported from a vector file in the Quartus Waveform Editor and apply to  
-- the top level entity of the current Quartus project .The user can use this   
-- testbench to simulate his design using a third-party simulation tool .       
-- *****************************************************************************
-- Generated on "12/04/2019 13:27:33"
                                                             
-- Vhdl Test Bench(with test vectors) for design  :          Template_2019
-- 
-- Simulation tool : 3rd Party
-- 

LIBRARY ieee;                                               
USE ieee.std_logic_1164.all;                                

ENTITY Template_2019_vhd_vec_tst IS
END Template_2019_vhd_vec_tst;
ARCHITECTURE Template_2019_arch OF Template_2019_vhd_vec_tst IS
-- constants                                                 
-- signals                                                   
SIGNAL CLOCK_50Mhz : STD_LOGIC;
SIGNAL DATA4 : STD_LOGIC_VECTOR(3 DOWNTO 0);
SIGNAL KEY : STD_LOGIC_VECTOR(1 DOWNTO 0);
SIGNAL LED : STD_LOGIC_VECTOR(7 DOWNTO 0);
SIGNAL SEL : STD_LOGIC_VECTOR(1 DOWNTO 0);
COMPONENT Template_2019
	PORT (
	CLOCK_50Mhz : IN STD_LOGIC;
	DATA4 : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
	KEY : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
	LED : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
	SEL : IN STD_LOGIC_VECTOR(1 DOWNTO 0)
	);
END COMPONENT;
BEGIN
	i1 : Template_2019
	PORT MAP (
-- list connections between master ports and signals
	CLOCK_50Mhz => CLOCK_50Mhz,
	DATA4 => DATA4,
	KEY => KEY,
	LED => LED,
	SEL => SEL
	);
-- DATA4[3]
t_prcs_DATA4_3: PROCESS
BEGIN
	DATA4(3) <= '0';
	WAIT FOR 320000 ps;
	DATA4(3) <= '1';
	WAIT FOR 320000 ps;
	DATA4(3) <= '0';
	WAIT FOR 320000 ps;
	DATA4(3) <= '1';
WAIT;
END PROCESS t_prcs_DATA4_3;
-- DATA4[2]
t_prcs_DATA4_2: PROCESS
BEGIN
	FOR i IN 1 TO 3
	LOOP
		DATA4(2) <= '0';
		WAIT FOR 160000 ps;
		DATA4(2) <= '1';
		WAIT FOR 160000 ps;
	END LOOP;
	DATA4(2) <= '0';
WAIT;
END PROCESS t_prcs_DATA4_2;
-- DATA4[1]
t_prcs_DATA4_1: PROCESS
BEGIN
	FOR i IN 1 TO 6
	LOOP
		DATA4(1) <= '0';
		WAIT FOR 80000 ps;
		DATA4(1) <= '1';
		WAIT FOR 80000 ps;
	END LOOP;
	DATA4(1) <= '0';
WAIT;
END PROCESS t_prcs_DATA4_1;
-- DATA4[0]
t_prcs_DATA4_0: PROCESS
BEGIN
	FOR i IN 1 TO 12
	LOOP
		DATA4(0) <= '0';
		WAIT FOR 40000 ps;
		DATA4(0) <= '1';
		WAIT FOR 40000 ps;
	END LOOP;
	DATA4(0) <= '0';
WAIT;
END PROCESS t_prcs_DATA4_0;
-- KEY[1]
t_prcs_KEY_1: PROCESS
BEGIN
	FOR i IN 1 TO 3
	LOOP
		KEY(1) <= '0';
		WAIT FOR 162000 ps;
		KEY(1) <= '1';
		WAIT FOR 162000 ps;
	END LOOP;
	KEY(1) <= '0';
WAIT;
END PROCESS t_prcs_KEY_1;
-- KEY[0]
t_prcs_KEY_0: PROCESS
BEGIN
	FOR i IN 1 TO 6
	LOOP
		KEY(0) <= '0';
		WAIT FOR 81000 ps;
		KEY(0) <= '1';
		WAIT FOR 81000 ps;
	END LOOP;
	KEY(0) <= '0';
WAIT;
END PROCESS t_prcs_KEY_0;
END Template_2019_arch;