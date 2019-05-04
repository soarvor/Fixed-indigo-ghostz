#pragma once

#include "../Main/Main.h"

#define FIX_MIN_FOV_HEAD	30
#define FIX_MIN_FOV_CHEST	50
#define FOV_BASE_DISTANCE	200

struct k_weapon_data {
	int itemDefinitionIndex;
	int paintKit;
	int rarity;
	int seed;
	float wear;
	char* name = "";
};

namespace Settings
{
	void LoadSettings( string szIniFile );
	void SaveSettings( string szIniFile );
	extern float hitmarkerAlpha;

	namespace MedalChanger {
		extern bool enabled;
		extern std::vector<uint32_t> medals;
		extern bool equipped_medal_override;
		extern uint32_t equipped_medal;
	}
	namespace ProfileChanger {
		extern bool enabled;
		extern int rank_id;
		extern int wins;
		extern int cmd_friendly;
		extern int cmd_leader;
		extern int cmd_teaching;
		extern int level;
		extern int xp;
	}
	namespace InventoryChanger {
		extern bool enabled;
		extern std::vector<k_weapon_data> weapons;
	}

	namespace Aimbot
	{
		struct weapon_aim_s
		{
			//[swap_lines]
			bool aim_Active;
			int aim_Smooth;
			int aim_Fov;
			int aim_FovType;
			int aim_BestHit;
			int aim_Spot;
			int aim_Delay;
			int aim_Rcs;
			int aim_RcsFov;
			int aim_RcsSmooth;
			int aim_RcsClampType;
			//[/swap_lines]
		};
		//[swap_lines]
		extern int aim_Backtracktime;
		extern bool aim_Backtrack;
		extern bool aim_DrawBacktrack;
		extern bool aim_Deathmatch;
		extern bool aim_WallAttack;
		extern bool aim_CheckSmoke;
		extern bool aim_AntiJump;
		extern int aim_RcsType;
		extern bool aim_DrawFov;
		extern bool aim_DrawSpot;
		
		extern weapon_aim_s weapon_aim_settings[33];
		//[/swap_lines]
	}

	namespace Esp
	{
		//[swap_lines]
		extern int esp_Style; // 0 - Box 1 - CoalBox
		extern int esp_Size;
		extern bool esp_Line;
		extern bool esp_Outline; // Box ( 0 - Box 1 - OutlineBox ) ,
						  // CoalBox ( 0 - CoalBox 1 - OutlineCoalBox )	

		extern bool esp_Time;
		extern bool esp_Watermark;
		extern bool esp_Name;
		extern bool esp_Rank;
		extern bool esp_Radar;
		extern int esp_Health;
		extern int esp_Armor;
		extern bool esp_Weapon;
		extern bool esp_Distance;
		extern bool esp_Sound;
		extern bool esp_GrenadePrediction;
		extern bool esp_NightMode;

		extern float esp_Ambient[3];

		extern bool esp_HitMarker;
		extern int esp_HitMarkerSound;
		extern float esp_HitMarkerColor[3];

		extern bool esp_LegitAAIndicator;
		extern bool esp_Skeleton;
		extern int esp_BulletTrace;
		extern float flTracer_Beam[3];
		extern bool esp_beams_tracer;
		extern float flTracersDuration;
		extern float flTracersWidth;
		extern bool esp_Team;
		extern bool esp_Enemy;
		extern int esp_Visible;
		extern int esp_ChamsVisible;

		extern int esp_Chams;
		extern bool esp_HealthChams;
		extern bool esp_Bomb;
		extern bool esp_Defusing;
		extern int esp_BombTimer;
		extern bool esp_WorldWeapons;
		extern bool esp_WorldGrenade;
		extern bool esp_BoxNade;

		extern float esp_Color_CT[3];
		extern float esp_Color_TT[3];
		extern float esp_Color_VCT[3];
		extern float esp_Color_VTT[3];

		extern float chams_Color_CT[3];
		extern float chams_Color_TT[3];
		extern float chams_Color_VCT[3];
		extern float chams_Color_VTT[3];
		//[/swap_lines]
	}

	namespace Skin
	{
		//[swap_lines]
		extern int knf_ct_model;
		extern int knf_ct_skin;
		extern int knf_tt_model;
		extern int knf_tt_skin;
		extern int gloves_skin;
		extern bool SkinIDs;
		extern bool MedalIDs;
		//[/swap_lines]
	}

	namespace Misc
	{
		//[swap_lines]
		extern QAngle qLastTickAngle;
		extern const char* misc_SkyName;
		extern int misc_CurrentSky;
		extern bool misc_SkinChanger;
		extern bool misc_KnifeChanger;
		extern bool misc_NoSky;
		extern bool misc_Bhop;
		extern char misc_namechanger;
		extern int misc_Clan;
		extern bool misc_spamrandom;
		extern bool misc_AwpAim;
		extern bool misc_NoFlash;	
		extern bool misc_NoSmoke;
		extern bool misc_NoHands;
		extern bool misc_LegitAA;
		extern bool misc_LegitAAToggle;
		extern bool misc_AutoAccept;
		extern bool misc_Spectators;
		extern float misc_RainbowSpeed;
		extern bool misc_FovChanger;
		extern int misc_FovView;
		extern int misc_FovModelView;
		extern bool InvAlwaysOn;
		extern float hitmarkerAlpha;
	}
}

#define CHEAT_NAME "haha yeet"
#define WATER_MARK "haha yeet"
#define AIMBOT_TEXT "A"
#define COLORS_TEXT "Colors"
#define CONFIG_TEXT "C"
#define TRIGGER_TEXT "Triggerbot"
#define VISUAL_TEXT "V"
#define SKIN_TEXT "S"
#define MISC_TEXT "M"

#define CVAR_AIMBOT_DEATHMATCH "aim_Deathmatch"
#define CVAR_AIMBOT_WALLATTACK "aim_WallAttack"
#define CVAR_AIMBOT_CHECKSMOKE "aim_CheckSmoke"
#define CVAR_AIMBOT_ANTIJUMP	"aim_IgnoreJump"
#define CVAR_AIMBOT_RCSTYPE "aim_RcsType"
#define CVAR_AIMBOT_DRAWFOV "aim_DrawFov"
#define CVAR_AIMBOT_DRAWSPOT "aim_DrawSpot"
#define CVAR_AIMBOT_BACKTRACK "aim_Backtrack"
#define CVAR_AIMBOT_BACKTRACK_TICK "aim_Backtracktickrate"

#define CVAR_AIMBOT_ACTIVE "aim_Active"
#define CVAR_AIMBOT_SMOOTH "aim_Smooth"
#define CVAR_AIMBOT_FOV "aim_Fov"
#define CVAR_AIMBOT_FOVTYPE "aim_FovType"
#define CVAR_AIMBOT_BESTHIT "aim_BestHit"
#define CVAR_AIMBOT_SPOT "aim_Spot"
#define CVAR_AIMBOT_DELAY "aim_Delay"

#define CVAR_AIMBOT_RCS "aim_Rcs"
#define CVAR_AIMBOT_RCSFOV "aim_RcsFov"
#define CVAR_AIMBOT_RCSSMOOTH "aim_RcsSmooth"
#define CVAR_AIMBOT_RCSCLAMPTYPE "aim_RcsClampType"

#define CVAR_ESP_TEAM "ESP_Team"
#define CVAR_ESP_ENEMY "ESP_Enemy"
#define CVAR_ESP_BOMB "ESP_Bomb"
#define CVAR_ESP_LINE "ESP_Line"
#define CVAR_ESP_OUTLINE "ESP_Outline"
#define CVAR_ESP_NAME "ESP_Name"
#define CVAR_ESP_RANK "ESP_Rank"
#define CVAR_ESP_RADAR "ESP_Radar"
#define CVAR_ESP_WEAPON "ESP_Weapon"
#define CVAR_ESP_DISTANCE "ESP_Distance"
#define CVAR_ESP_SKELETON "ESP_Skeleton"
#define CVAR_ESP_WORLDWEAPONS "ESP_WorldWeapons"
#define CVAR_ESP_WORLDGRENADE "ESP_WorldGrenade"
#define CVAR_ESP_BOXNADE "ESP_BoxNade"
#define CVAR_ESP_GRENADEPREDICTION "ESP_GrenadePrediction"
#define CVAR_ESP_WATER "ESP_Watermark"
#define CVAR_ESP_TIME "ESP_Time"

#define CVAR_ESP_STYLE "ESP_Style"
#define CVAR_ESP_VISIBLE "ESP_Visible"
#define CVAR_ESP_SIZE "ESP_Size"

#define CVAR_ESP_CHAMS "ESP_Chams"
#define CVAR_ESP_CHAMSVISIBLE "ESP_ChamsVisible"

#define CVAR_ESP_BOMBTIMER "ESP_BombTimer"
#define CVAR_ESP_BULLETTRACE "ESP_BulletTrace"
#define CVAR_ESP_BEAMS_TRACER "ESP_Beams_Tracer"
#define CVAR_ESP_FLTRACERSDURATION "ESP_flTracersDuration"
#define CVAR_ESP_FLTRACERSWIDTH "ESP_flTracersWidth"
#define CVAR_ESP_HEALTH "ESP_Health"
#define CVAR_ESP_ARMOR "ESP_Armor"

#define CVAR_ESP_HITMARKER "ESP_HitMarker"
#define CVAR_ESP_HITMARKER_SOUND "ESP_HitMarkerSound"
#define CVAR_ESP_HITMARKER_COLOR "ESP_HitMarkerColor"

#define CVAR_ESP_COLOR_CT "ESP_Color_CT"
#define CVAR_ESP_COLOR_VCT "ESP_Color_VCT"
#define CVAR_CHAMS_COLOR_CT "chams_Color_CT"
#define CVAR_CHAMS_COLOR_VCT "chams_Color_VCT"

#define CVAR_ESP_COLOR_TT "ESP_Color_TT"
#define CVAR_ESP_COLOR_VTT "ESP_Color_VTT"
#define CVAR_CHAMS_COLOR_TT "chams_Color_TT"
#define CVAR_CHAMS_COLOR_VTT "chams_Color_VTT"

#define C4_TIMER_STRING "C4 Timer: %0.2f"

#define CVAR_SKIN_CT_MODEL "knf_ct_model"
#define CVAR_SKIN_CT_SKIN "knf_ct_skin"
#define CVAR_SKIN_TT_MODEL "knf_tt_model"
#define CVAR_SKIN_TT_SKIN "knf_tt_skin"
#define CVAR_SKIN_GLOVES "gloves_skin"

#define CVAR_MISC_AUTOACCEPT "misc_AutoAccept"
#define CVAR_MISC_AWPAIM "misc_AwpAim"
#define CVAR_MISC_BHOP "misc_Bhop"
#define CVAR_MISC_NOFLASH "misc_NoFlash"
#define CVAR_MISC_NOSMOKE "misc_NoSmoke"
#define CVAR_MISC_NOHANDS "misc_NoHands"
#define CVAR_MISC_LEGITAA "misc_LegitAA"
#define CVAR_ESP_LEGITAAINDICATOR "esp_LegitAAIndicator"
#define LEGITAALEFT "Left"
#define LEGITAARIGHT "Right"
#define CVAR_MISC_LEGITAATOGGLE "misc_LegitAAToggle"
#define CVAR_MISC_SPECTATORS "misc_Spectators"
#define CVAR_MISC_FOV_CHANGER "misc_FovChanger"
#define CVAR_MISC_FOV_VIEW "misc_FovView"
#define CVAR_MISC_FOV_MDL_VIEW "misc_FovModelView"
#define CVAR_MISC_INVALWAYSON "misc_InvAlwaysOn"