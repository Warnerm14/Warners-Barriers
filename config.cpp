/*
	Warner's Barriers for Arma 3
	
	Author: Matthew Warner (Warnerm14)
	Discord: Warnerm14#3936
	Site: www.twitter.com/Warnerm14

	With edits by: <Your Name Here>
		
	Permission: 
		You may use the Warners-Barriers.pbo on your server without receiving permission from the Author.
		You may redistribute the Warners-Barriers.pbo as long as you give proper credit to the Author. 
		You may not remove any code from the Warners-Barriers.pbo to use in your own mods/mission/projects without permission from the Author.
		You may repack the Warners-Barriers.pbo with edits made to the code as long as you do not modify the comment blocks. (Except the "With edits by:" part).
		
	File Desc: This is where functions and items are defined.
*/

class CfgPatches {
	class warners_barriers {
		name = "Warner's Barriers";
		author = "Matthew Warner (Warnerm14)";
		url = "https://twitter.com/Warnerm14";
				
		requiredVersion = 0.1;
		requiredAddons[] = {};
		units[] = {};
		weapons[] = {};
	};
};

class CfgFunctions
{
    class warnerBarriers
    {
        class functions
        {
            file = "\Warners-Barriers\scripts";
            class init {postInit = 1;};
            class invController {};
            class grabItem {};
            class globalUpdate {};
        };
    };
};

class cfgMagazines
{
	class CA_Magazine;
	class warn_baseItem : CA_Magazine
	{
		mass = 1;
		scope = 0;
		
		warner_placeable = 1;
		warner_pos = "[0, 2, 0.35]";
		warner_dir = 0;
		warner_allowDamage = 1;
		warner_texture[] = {};
		
		author = "Warnerm14";
		model = "\A3\weapons_F\ammo\mag_univ.p3d";
		picture = "\Warners-Barriers\textures\blank_ico.paa";
	};
	
	/*================Your custom items!=================*/
	
	class warn_customItem : warn_baseItem
	{
		mass = 1; // Mass of the item.
		scope = 0; // INORDER FOR YOUR ITEM TO BE IN GAME, THIS MUST BE EQUAL TO 2
				
		displayName = "My Barrier"; // Name that appears in your inventory.
		
		warner_dir = 0; // If the item is turned when you pull it out of your inventory, set this to 90.
		warner_class = "my_barrier_f"; // Classname of the barrier itself.	
		warner_pos = "[0, 4, 4.35]"; // The position that is used to attach it to the player.
		warner_allowDamage = 1;	// Should the item have god mode? 0 = yes, 1 = no
		warner_texture[] = {{0,"texture path 1"},{1,"texture path 2"}}; // Delete if not in use, ARRAY MUST BE NESTED AS SHOWN.
	};
	
	/*===================================================*/
	
	class warn_cone: warn_baseItem
	{
		mass = 0.2;
		scope = 2;
		displayName = "Road Cone";
		warner_class = "RoadCone_F";	
	};
	
	class warn_coneLight: warn_baseItem
	{
		mass = 0.3;
		scope = 2;
		displayName = "Road Cone w/ Light";
		warner_class = "RoadCone_L_F";		
	};
	
	class warn_plasticBarrier1_orange: warn_baseItem
	{
		mass = 1;
		scope = 2;
		displayName = "Plastic Barrier (Orange)";
		warner_class = "PlasticBarrier_03_orange_F";		
	};
	
	class warn_plasticBarrier1_blue: warn_baseItem
	{
		mass = 1;
		scope = 2;
		displayName = "Plastic Barrier (Blue)";
		warner_class = "PlasticBarrier_03_blue_F";		
	};
	
	class warn_plasticBarrier2_yellow: warn_baseItem
	{
		mass = 1;
		scope = 2;
		displayName = "Plastic Barrier (Yellow)";
		warner_class = "PlasticBarrier_02_yellow_F";		
	};
	
	class warn_plasticBarrier2_grey: warn_baseItem
	{
		mass = 1;
		scope = 2;
		displayName = "Plastic Barrier (Grey)";
		warner_class = "PlasticBarrier_02_grey_F";		
	};
	
	class warn_roadbarrier: warn_baseItem
	{
		mass = 2.5;
		scope = 2;
		displayName = "Road Barrier";
		warner_pos = "[0, 2, 0.65]";
		warner_class = "RoadBarrier_F";		
	};
	
	class warn_roadbarrierSmall: warn_baseItem
	{
		mass = 1;
		scope = 2;
		displayName = "Road Barrier Small w/ Light";
		warner_pos = "[0, 2, 0.8]";
		warner_class = "RoadBarrier_small_F";		
	};
	
	class warn_portableLamp_single: warn_baseItem
	{
		mass = 1;
		scope = 2;
		displayName = "Portable Lights (Single)";
		warner_pos = "[0, 0.6, 1.1]";
		warner_dir = 180;
		warner_class = "Land_PortableLight_single_F";		
	};
	
	class warn_portableLamp_double: warn_baseItem
	{
		mass = 1;
		scope = 2;
		displayName = "Portable Lights (Double)";
		warner_pos = "[0, 0.6, 1.1]";
		warner_dir = 180;
		warner_class = "Land_PortableLight_double_F";		
	};
	
	class warn_bargate: warn_baseItem
	{
		mass = 4;
		scope = 2;
		
		displayName = "Bar Gate";
		warner_class = "Land_BarGate_F";	
		warner_pos = "[0, 4, 4.35]";
		warner_allowDamage = 0;	
	};
	
	class warn_checkpointSign: warn_baseItem
	{
		mass = 4;
		scope = 2;
		
		displayName = "Sign (PD Checkpoint)";
		warner_class = "SignAd_Sponsor_F";	
		warner_allowDamage = 0;	
		warner_texture[] = {{0,"\warners-barriers\textures\checkpoint_sign.paa"}};	
	};
};

class CfgVehicles
{
	class Box_NATO_Wps_F;
	class warner_barrierBox: Box_NATO_Wps_F
	{
		author="Warnerm14";
		displayName="Warner's Barriers Items";
		class TransportMagazines
		{
			class _xx_warn_cone
			{
				magazine="warn_cone";
				count=50;
			};
			class _xx_warn_coneLight
			{
				magazine="warn_coneLight";
				count=50;
			};
			class _xx_warn_plasticBarrier1_orange
			{
				magazine="warn_plasticBarrier1_orange";
				count=50;
			};
			class _xx_warn_plasticBarrier1_blue
			{
				magazine="warn_plasticBarrier1_blue";
				count=50;
			};
			class _xx_warn_plasticBarrier2_yellow
			{
				magazine="warn_plasticBarrier2_yellow";
				count=50;
			};
			class _xx_warn_plasticBarrier2_grey
			{
				magazine="warn_plasticBarrier2_grey";
				count=50;
			};
			class _xx_warn_roadbarrier
			{
				magazine="warn_roadbarrier";
				count=50;
			};
			class _xx_warn_roadbarrierSmall
			{
				magazine="warn_roadbarrierSmall";
				count=50;
			};
			class _xx_warn_portableLamp_single
			{
				magazine="warn_portableLamp_single";
				count=50;
			};
			class _xx_warn_portableLamp_double
			{
				magazine="warn_portableLamp_double";
				count=50;
			};
			class _xx_warn_bargate
			{
				magazine="warn_bargate";
				count=50;
			};
			class _xx_warn_checkpointSign
			{
				magazine="warn_checkpointSign";
				count=50;
			};
		};
		class TransportWeapons{};
		class TransportItems{};
	};
};