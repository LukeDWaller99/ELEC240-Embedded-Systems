library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity LED_latch is

	port
	(
		--input ports
		latch 	: in std_logic;	--input for the latch
		input1	: in std_logic;	--input for LEDs
		input2	: in std_logic;
		input3	: in std_logic;
		input4	: in std_logic;
		
		--output ports 
		LED1	: out std_logic;		--output for LEDs 
		LED2	: out std_logic;
		LED3	: out std_logic;	
		LED4	: out std_logic
	);
end LED_latch;

architecture LED_latch of LED_latch is

begin 
	process(latch)
	begin
		if(latch = '1') then			--when the latch is high 
			LED1 <= input1;			--all of the inputs are mapped
			LED2 <= input2;			--to thier respective outputs 
			LED3 <= input3;			--these are then held until the 
			LED4 <= input4;			--the latch goes high again 
		end if;
	end process;
end LED_latch;
