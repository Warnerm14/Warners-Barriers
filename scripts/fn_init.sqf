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
		
	File Desc: This file is ran on player init via postInit, it sets up Variable, Add Actions, and Event Handlers.
*/

waitUntil {!(IsNull (findDisplay 46))};
warn_placeable = objNull;

/*If you add something and you don't get the pickup option on it, add its classname to this list.*/
warn_noCursorObject = ["RoadBarrier_F","Land_BarGate_F"]; 

if (isNil {player getVariable "canUseBarriers"}) then {
	player setVariable ["canUseBarriers",true,true];
};

player addAction [("<t color=""#0066d1"">" + ("Drop") +"</t>"),{detach warn_placeable; warn_placeable setVectorUP (surfaceNormal [(getPosATL warn_placeable) select 0,(getPosATL warn_placeable) select 1]); [getPos warn_placeable, getDir warn_placeable, warn_placeable] remoteExecCall ["warner_fnc_globalUpdate",-2,false]; warn_placeable = objNull;},[""],0.1,false,true,"","player getVariable 'canUseBarriers' && { if (_x getVariable 'placeable') exitWith {true;}; } forEach attachedObjects player  && vehicle player == player"];
player addAction [("<t color=""#0066d1"">" + ("Pickup") +"</t>"),{player addMagazine (cursorObject getVariable "class"); deleteVehicle cursorObject;},[""],0.1,false,true,"","player getVariable 'canUseBarriers' && (count (attachedObjects player)) == 0 && cursorObject getVariable 'placeable' && (player distance cursorObject) <= 2 && vehicle player == player"];

player addAction [("<t color=""#0066d1"">" + ("Pickup") +"</t>"),{player addMagazine (((nearestObjects [player, warn_noCursorObject, 5]) select 0) getVariable "class"); deleteVehicle ((nearestObjects [player, warn_noCursorObject, 5]) select 0);},[""],0.1,false,true,"","player getVariable 'canUseBarriers' && (count (attachedObjects player)) == 0 && ((nearestObjects [player, warn_noCursorObject, 5]) select 0) getVariable 'placeable' && (player distance ((nearestObjects [player, warn_noCursorObject, 5]) select 0)) <= 1 && vehicle player == player"];

player addEventHandler ["InventoryOpened", {
	handle = false;
	[] spawn {
		uiSleep 0.05;
		waitUntil {!(isNull (findDisplay 602)) || handle };
		if(!handle) then {
			((findDisplay 602) displayCtrl 638) ctrlSetEventHandler ["LBDblClick", "_this call warner_fnc_invController"];  
			((findDisplay 602) displayCtrl 633) ctrlSetEventHandler ["LBDblClick", "_this call warner_fnc_invController"];  
			((findDisplay 602) displayCtrl 640) ctrlSetEventHandler ["LBDblClick", "_this call warner_fnc_invController"];  
			((findDisplay 602) displayCtrl 619) ctrlSetEventHandler ["LBDblClick", "_this call warner_fnc_invController"];
		}; 
	};
}];