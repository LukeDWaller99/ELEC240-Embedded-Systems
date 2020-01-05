library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity multiplexer is 

	port 
	(
		--input ports 
		packet_selector 	: in std_logic;
		led_flash		 	: in std_logic;
		Input 				: in std_logic_vector (3 downto 0);
		
		--output ports
		Output				: out std_logic_vector (7 downto 0)
	);
end multiplexer;

architecture multiplexer of multiplexer is 

begin 
	process(led_flash)
		begin
			if(led_flash = '1') then --if the flash input is high 
	
				if(packet_selector = '0') then --if the packet selector is 0
				Output (3 downto 0) <= Input (3 downto 0); -- set the inputs to the outputs 0 - 3 
				end if;
		
				else if (packet_selector = '1') then --if the packet selector is 1
				Output (7 downto 4) <= Input (3 downto 0); -- set the inputs to the outputs 7 - 4 
				end if;
				
			end if;
		end process;
end multiplexer;	
	