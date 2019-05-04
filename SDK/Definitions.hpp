#pragma once

#include <Windows.h>

#ifndef CONCAT_IMPL
#define CONCAT_IMPL(x, y) x##y
#ifndef MACRO_CONCAT
#define MACRO_CONCAT(x, y) CONCAT_IMPL(x, y)
#ifndef PAD
#define PAD(SIZE) BYTE MACRO_CONCAT(_pad, __COUNTER__)[SIZE];
#endif
#endif
#endif

#define VirtualFn( cast ) typedef cast( __thiscall* OriginalFn )

template< typename Function > Function GetMethod( PVOID Base , DWORD Index )
{
	PDWORD* VTablePointer = (PDWORD*)Base;
	PDWORD VTableFunctionBase = *VTablePointer;
	DWORD dwAddress = VTableFunctionBase[Index];
	return (Function)( dwAddress );
}

typedef struct con_nprint_s
{
	int		index;			// Row #
	float	time_to_live;	// # of seconds before it disappears. -1 means to display for 1 frame then go away.
	float	color[3];		// RGB colors ( 0.0 -> 1.0 scale )
	bool	fixed_width_font;
} con_nprint_t;

struct ScreenFade_t
{
	unsigned short 	duration;		// FIXED 16 bit, with SCREENFADE_FRACBITS fractional, seconds duration
	unsigned short 	holdTime;		// FIXED 16 bit, with SCREENFADE_FRACBITS fractional, seconds duration until reset (fade & hold)
	short			fadeFlags;		// flags
	byte			r , g , b , a;		// fade to color ( max alpha )
};

struct CHudTexture
{
	char	szShortName[64];	//0x0000
	char	szTextureFile[64];	//0x0040
	bool	bRenderUsingFont;	//0x0080
	bool	bPrecached;			//0x0081
	char	cCharacterInFont;	//0x0082
	BYTE	pad_0x0083;			//0x0083
	int		hFont;				//0x0084
	int		iTextureId;			//0x0088
	float	afTexCoords[4];		//0x008C
	int		iPosX[4];			//0x009C
}; //Size=0x00AC

class CWeaponInfo
{
public:
	/* Old
	void*   vftbl;                             //0x0000
	char*   consoleName;                       //0x0004
	char    pad_0x0008[12];                    //0x0008
	int     iMaxClip1;                         //0x0014
	int     iMaxClip2;                         //0x0018
	int     iDefaultClip1;                     //0x001C
	int     iDefaultClip2;                     //0x0020
	int     iMaxReservedAmmo;                  //0x0024
	char    pad_0x0028[8];                     //0x0028
	char*   szWorldModel;                      //0x0030
	char*   szViewModel;                       //0x0034
	char*   szDroppedModel;                    //0x0038
	char    pad_0x003C[64];                    //0x003C
	char*   szEmptySound;                      //0x007C
	char    pad_0x0080[4];                     //0x0080
	char*   szBulletType;                      //0x0084
	char*   szHudName;                         //0x0088
	char*   szWeaponName;                      //0x008C
	char    pad_0x0090[60];                    //0x0090
	int     WeaponType;                        //0x00CC
	int     iWeaponPrice;                      //0x00D0
	int     iKillAward;                        //0x00D4
	char*   szAnimationPrefix;                 //0x00D8
	float   flCycleTime;                       //0x00DC
	float   flCycleTimeAlt;                    //0x00E0
	float   flTimeToIdle;                      //0x00E4
	float   flIdleInterval;                    //0x00E8
	bool    bFullAuto;                         //0x00EC
	char    pad_0x00ED[3];                     //0x00ED
	int     iDamage;                           //0x00F0
	float   flArmorRatio;                      //0x00F4
	int     iBullets;                          //0x00F8
	float   flPenetration;                     //0x00FC
	float   flFlinchVelocityModifierLarge;     //0x0100
	float   flFlinchVelocityModifierSmall;     //0x0104
	float   flRange;                           //0x0108
	float   flRangeModifier;                   //0x010C
	float   flThrowVelocity;                   //0x0110
	char    pad_0x0114[12];                    //0x0114
	bool    bHasSilencer;                      //0x0120
	char    pad_0x0121[3];                     //0x0121
	char*   pSilencerModel;                    //0x0124
	int     iCrosshairMinDistance;             //0x0128
	int     iCrosshairDeltaDistance;           //0x012C
	float   flMaxPlayerSpeed;                  //0x0130
	float   flMaxPlayerSpeedAlt;               //0x0134
	float   flSpread;                          //0x0138
	float   flSpreadAlt;                       //0x013C
	float   flInaccuracyCrouch;                //0x0140
	float   flInaccuracyCrouchAlt;             //0x0144
	float   flInaccuracyStand;                 //0x0148
	float   flInaccuracyStandAlt;              //0x014C
	float   flInaccuracyJumpInitial;           //0x0150
	float   flInaccuracyJump;                  //0x0154
	float   flInaccuracyJumpAlt;               //0x0158
	float   flInaccuracyLand;                  //0x015C
	float   flInaccuracyLandAlt;               //0x0160
	float   flInaccuracyLadder;                //0x0164
	float   flInaccuracyLadderAlt;             //0x0168
	float   flInaccuracyFire;                  //0x016C
	float   flInaccuracyFireAlt;               //0x0170
	float   flInaccuracyMove;                  //0x0174
	float   flInaccuracyMoveAlt;               //0x0178
	float   flInaccuracyReload;                //0x017C
	char    pad_0x0180[4];                     //0x0180
	int     iRecoilSeed;                       //0x0184
	float   flRecoilAngle;                     //0x0188
	float   flRecoilAngleAlt;                  //0x018C
	float   flRecoilAngleVariance;             //0x0190
	float   flRecoilAngleVarianceAlt;          //0x0194
	float   flRecoilMagnitude;                 //0x0198
	float   flRecoilMagnitudeAlt;              //0x019C
	float   flRecoilMagnitudeVariance;         //0x01A0
	float   flRecoilMagnitudeVarianceAlt;      //0x01A4
	float   flRecoveryTimeCrouch;              //0x01A8
	float   flRecoveryTimeStand;               //0x01AC
	float   flRecoveryTimeCrouchFinal;         //0x01B0
	float   flRecoveryTimeStandFinal;          //0x01B4
	int     iRecoveryTransitionStartBullet;    //0x01B8
	int     iRecoveryTransitionEndBullet;      //0x01BC
	bool    bUnzoomAfterShot;                  //0x01C0
	bool    bHideViewModelZoomed;              //0x01C1
	char    pad_0x01C2[2];                     //0x01C2
	char    iZoomLevels[3];                    //0x01C4
	int     iZoomFOV[2];                       //0x01C7
	float   fZoomTime[3];                      //0x01C9
	char*   szWeaponClass;                     //0x01CC
	float   flAddonScale;                      //0x01D0
	char    pad_0x01D4[4];                     //0x01D4
	char*   szEjectBrassEffect;                //0x01D8
	char*   szTracerEffect;                    //0x01DC
	int     iTracerFrequency;                  //0x01E0
	int     iTracerFrequencyAlt;               //0x01E4
	char*   szMuzzleFlashEffect_1stPerson;     //0x01E8
	char    pad_0x01EC[4];                     //0x01EC
	char*   szMuzzleFlashEffect_3rdPerson;     //0x01F0
	char    pad_0x01F4[4];                     //0x01F4
	char*   szMuzzleSmokeEffect;               //0x01F8
	float   flHeatPerShot;                     //0x01FC
	char*   szZoomInSound;                     //0x0200
	char*   szZoomOutSound;                    //0x0204
	float   flInaccuracyPitchShift;            //0x0208
	float   flInaccuracySoundThreshold;        //0x020C
	float   flBotAudibleRange;                 //0x0210
	char    pad_0x0214[8];                     //0x0214
	char*   pWrongTeamMsg;                     //0x021C
	bool    bHasBurstMode;                     //0x0220
	char    pad_0x0221[3];                     //0x0221
	bool    bIsRevolver;                       //0x0224
	bool    bCannotShootUnderwater;            //0x0225
	*/

	// New
	void*   vftbl;                             //0x0000
	char*   consoleName;                       //0x0004
	char    pad_0x0000[20];					   // New
	char    pad_0x0008[12];                    //0x0008
	int     iMaxClip1;                         //0x0014
	int     iMaxClip2;                         //0x0018
	char    pad_0x0018[12];					   // New
	int     iDefaultClip1;                     //0x001C
	int     iDefaultClip2;                     //0x0020
	int     iMaxReservedAmmo;                  //0x0024
	char    pad_0x0028[96];					   // New
	char*   szWorldModel;                      //0x0030
	char*   szViewModel;                       //0x0034
	char*   szDroppedModel;                    //0x0038
	char    pad_0x003C[64];                    //0x003C
	char*   szEmptySound;                      //0x007C
	char    pad_0x0080[4];                     //0x0080
	char*   szBulletType;                      //0x0084
	char*   szHudName;                         //0x0088
	char*   szWeaponName;                      //0x008C
	char    pad_0x0090[60];                    //0x0090
	int     WeaponType;                        //0x00CC
	int     iWeaponPrice;                      //0x00D0
	int     iKillAward;                        //0x00D4
	char    pad_0x00D8[20];					   // New
	char*   szAnimationPrefix;                 //0x00D8
	float   flCycleTime;                       //0x00DC
	float   flCycleTimeAlt;                    //0x00E0
	float   flTimeToIdle;                      //0x00E4
	float   flIdleInterval;                    //0x00E8
	bool    bFullAuto;                         //0x00EC
	char    pad_0x00ED[3];                     //0x00ED
	int     iDamage;                           //0x00F0
	float   flArmorRatio;                      //0x00F4
	int     iBullets;                          //0x00F8
	float   flPenetration;                     //0x00FC
	char    pad_0x0100[8];					   // New
	float   flFlinchVelocityModifierLarge;     //0x0100
	float   flFlinchVelocityModifierSmall;     //0x0104
	float   flRange;                           //0x0108
	float   flRangeModifier;                   //0x010C
	char    pad_0x0110[16];					   // New
	float   flThrowVelocity;                   //0x0110
	char    pad_0x0114[12];                    //0x0114
	bool    bHasSilencer;                      //0x0120
	char    pad_0x0121[15];                    //0x0121
	char*   pSilencerModel;                    //0x0124
	int     iCrosshairMinDistance;             //0x0128
	int     iCrosshairDeltaDistance;           //0x012C
	float   flMaxPlayerSpeed;                  //0x0130
	float   flMaxPlayerSpeedAlt;               //0x0134
	char    pad_0x0138[76];					   // New
	float   flSpread;                          //0x0138
	float   flSpreadAlt;                       //0x013C
	float   flInaccuracyCrouch;                //0x0140
	float   flInaccuracyCrouchAlt;             //0x0144
	float   flInaccuracyStand;                 //0x0148
	float   flInaccuracyStandAlt;              //0x014C
	float   flInaccuracyJumpInitial;           //0x0150
	float   flInaccuracyJump;                  //0x0154
	float   flInaccuracyJumpAlt;               //0x0158
	float   flInaccuracyLand;                  //0x015C
	float   flInaccuracyLandAlt;               //0x0160
	float   flInaccuracyLadder;                //0x0164
	float   flInaccuracyLadderAlt;             //0x0168
	float   flInaccuracyFire;                  //0x016C
	float   flInaccuracyFireAlt;               //0x0170
	float   flInaccuracyMove;                  //0x0174
	float   flInaccuracyMoveAlt;               //0x0178
	float   flInaccuracyReload;                //0x017C
	char    pad_0x0180[4];                     //0x0180
	int     iRecoilSeed;                       //0x0184
	char	pad_0x0188[32];					   // New
	float   flRecoilAngle;                     //0x0188
	float   flRecoilAngleAlt;                  //0x018C
	float   flRecoilAngleVariance;             //0x0190
	float   flRecoilAngleVarianceAlt;          //0x0194
	float   flRecoilMagnitude;                 //0x0198
	float   flRecoilMagnitudeAlt;              //0x019C
	float   flRecoilMagnitudeVariance;         //0x01A0
	float   flRecoilMagnitudeVarianceAlt;      //0x01A4
	float   flRecoveryTimeCrouch;              //0x01A8
	float   flRecoveryTimeStand;               //0x01AC
	float   flRecoveryTimeCrouchFinal;         //0x01B0
	float   flRecoveryTimeStandFinal;          //0x01B4
	int     iRecoveryTransitionStartBullet;    //0x01B8
	int     iRecoveryTransitionEndBullet;      //0x01BC
	bool    bUnzoomAfterShot;                  //0x01C0
	bool    bHideViewModelZoomed;              //0x01C1
	char    pad_0x01C2[2];                     //0x01C2
	char    iZoomLevels[3];                    //0x01C4
	int     iZoomFOV[2];                       //0x01C7
	float   fZoomTime[3];                      //0x01C9
	char*   szWeaponClass;                     //0x01CC
	float   flAddonScale;                      //0x01D0
	char    pad_0x01D4[4];                     //0x01D4
	char*   szEjectBrassEffect;                //0x01D8
	char*   szTracerEffect;                    //0x01DC
	int     iTracerFrequency;                  //0x01E0
	int     iTracerFrequencyAlt;               //0x01E4
	char*   szMuzzleFlashEffect_1stPerson;     //0x01E8
	char    pad_0x01EC[4];                     //0x01EC
	char*   szMuzzleFlashEffect_3rdPerson;     //0x01F0
	char    pad_0x01F4[4];                     //0x01F4
	char*   szMuzzleSmokeEffect;               //0x01F8
	float   flHeatPerShot;                     //0x01FC
	char*   szZoomInSound;                     //0x0200
	char*   szZoomOutSound;                    //0x0204
	float   flInaccuracyPitchShift;            //0x0208
	float   flInaccuracySoundThreshold;        //0x020C
	float   flBotAudibleRange;                 //0x0210
	char    pad_0x0214[8];                     //0x0214
	char*   pWrongTeamMsg;                     //0x021C
	bool    bHasBurstMode;                     //0x0220
	char    pad_0x0221[3];                     //0x0221
	bool    bIsRevolver;                       //0x0224
	bool    bCannotShootUnderwater;            //0x0225
}; // Size = 0x0226
namespace SDK
{
	typedef void* ( *CreateInterfaceFn )( const char *pName , int *pReturnCode );
	typedef void* ( *InstantiateInterfaceFn )( );

	typedef void( *pfnDemoCustomDataCallback )( unsigned char *pData , size_t iSize );

	enum class FontFeature {
		FONT_FEATURE_ANTIALIASED_FONTS = 1 ,
		FONT_FEATURE_DROPSHADOW_FONTS = 2 ,
		FONT_FEATURE_OUTLINE_FONTS = 6 ,
	};

	enum class FontDrawType {
		FONT_DRAW_DEFAULT = 0 ,
		FONT_DRAW_NONADDITIVE ,
		FONT_DRAW_ADDITIVE ,
		FONT_DRAW_TYPE_COUNT = 2 ,
	};

	enum class FontFlags {
		FONTFLAG_NONE ,
		FONTFLAG_ITALIC = 0x001 ,
		FONTFLAG_UNDERLINE = 0x002 ,
		FONTFLAG_STRIKEOUT = 0x004 ,
		FONTFLAG_SYMBOL = 0x008 ,
		FONTFLAG_ANTIALIAS = 0x010 ,
		FONTFLAG_GAUSSIANBLUR = 0x020 ,
		FONTFLAG_ROTARY = 0x040 ,
		FONTFLAG_DROPSHADOW = 0x080 ,
		FONTFLAG_ADDITIVE = 0x100 ,
		FONTFLAG_OUTLINE = 0x200 ,
		FONTFLAG_CUSTOM = 0x400 ,
		FONTFLAG_BITMAP = 0x800 ,
	};

	enum class ClientFrameStage_t {
		FRAME_UNDEFINED = -1 ,
		FRAME_START ,
		FRAME_NET_UPDATE_START ,
		FRAME_NET_UPDATE_POSTDATAUPDATE_START ,
		FRAME_NET_UPDATE_POSTDATAUPDATE_END ,
		FRAME_NET_UPDATE_END ,
		FRAME_RENDER_START ,
		FRAME_RENDER_END
	};

	enum class ObserverMode_t : int
	{
		OBS_MODE_NONE = 0 ,
		OBS_MODE_DEATHCAM = 1 ,
		OBS_MODE_FREEZECAM = 2 ,
		OBS_MODE_FIXED = 3 ,
		OBS_MODE_IN_EYE = 4 ,
		OBS_MODE_CHASE = 5 ,
		OBS_MODE_ROAMING = 6
	};
}