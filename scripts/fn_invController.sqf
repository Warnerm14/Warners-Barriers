/*
	Warner's Barriers for Arma 3
	
	Author: Matthew Warner (Warnerm14)
	Site: www.twitter.com/Warnerm14
	
	With edits by: <Your Name Here>
		
	Permission: 
		You may use the Warners-Barriers.pbo on your server without receiving permission from the Author.
		You may redistribute the Warners-Barriers.pbo as long as you give proper credit to the Author.
		You may not remove any code from the Warners-Barriers.pbo to use in your own mods/mission/projects without permission from the Author.
		You may repack the Warners-Barriers.pbo with edits made to the code as long as you do not modify the comment blocks. (Except the "With edits by:" part).
		
	File Desc: This file is ran when you double click on an item in your inventory.
*/

if (!(player getVariable "canUseBarriers")) exitWith {};
_idc = ctrlIDC (_this select 0);          
_selectedIndex = _this select 1;  
_item = lbData [_idc, _selectedIndex];

_check = getNumber (configFile >> "CfgMagazines" >> _item >> "warner_placeable");
if (_check == 0) exitWith {};

[_item] spawn warner_fnc_grabItem;

closeDialog 0;
false;