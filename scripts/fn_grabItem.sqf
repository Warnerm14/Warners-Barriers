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
		
	File Desc: This file is ran when you double click on a valid item in your inventory.
*/

if (!(player getVariable "canUseBarriers")) exitWith {};
_item = _this select 0;
_class = getText (configFile >> "CfgMagazines" >> _item >> "warner_class");
_pos = getText (configFile >> "CfgMagazines" >> _item >> "warner_pos");
_dir = getNumber (configFile >> "CfgMagazines" >> _item >> "warner_dir");
_damage = getNumber (configFile >> "CfgMagazines" >> _item >> "warner_allowDamage");

_tmpPos = _pos splitString "[],";
_x = parseNumber (_tmpPos select 0);
_y = parseNumber (_tmpPos select 1);
_z = parseNumber (_tmpPos select 2);

_newPos = [_x,_y,_z];

warn_placeable = _class createVehicle position player;
if (isNull warn_placeable) exitWith {hint "Error: The classname for this object is not properly defined.";};
warn_placeable attachTo [player,_newPos];
warn_placeable setDir _dir;

warn_placeable setVariable ["placeable",true,true];
warn_placeable setVariable ["owner",getPlayerUID player,true];
warn_placeable setVariable ["class",_item,true];
if (_damage isEqualTo 0) then {
	warn_placeable allowDamage false;
};
player removeMagazine _item;