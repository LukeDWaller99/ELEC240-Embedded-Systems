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
		if(latch = '1') then
			LED1 <= input1;
			LED2 <= input2;
			LED3 <= input3;
			LED4 <= input4;
		end if;
	end process;
end LED_latch;
