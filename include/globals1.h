// globals.h
// this file will be automatically included by the driver
// for XKX mudlib, by Xiang

//added by DayDream
#define SAVE_EXTENSION __SAVE_EXTENSION__ 
//Solove the problem of MudOS version

//added by JackyBoy @ CCTX
#define PAWN            "/feature/pawn"
#define F_BANKER                "/feature/banker"
#define QUEST_OB                "/feature/quest_list"
#define EXPLIST         "/clone/quest/explist"
//added by JackyBoy @ CCTX for TOPTEN
#define TOPTEN_RICH     "/topten/rich.txt"
#define TOPTEN_PKER     "/topten/pker.txt"
#define TOPTEN_EXP      "/topten/exp.txt"
#define RICH_B "驰骋天下TOP TEN十大富人排行榜"
#define PKER_B "驰骋天下TOP TEN十大杀人狂排行榜"
#define EXP_B  "驰骋天下TOP TEN十大EXP高手排行榜"
#define TOPTEN_D                "/adm/daemons/toptend"

// Important directories
#define INC_DIR         "/include/"
#define COMMAND_DIR     "/cmds/"
#define CONFIG_DIR      "/adm/etc/"
#define DATA_DIR                "/data/"
#define HELP_DIR                "/help/"
#define LOG_DIR         "/log/"

// Daemons
#define ALIAS_D         "/adm/daemons/aliasd"
#define BAN_D           "/adm/daemons/band"
#define CHANNEL_D               "/adm/daemons/channeld"
#define CHAR_D          "/adm/daemons/chard"
#define CHINESE_D               "/adm/daemons/chinesed"
#define COMBAT_D                "/adm/daemons/combatd"
#define COMMAND_D               "/adm/daemons/commandd"
#define EMOTE_D         "/adm/daemons/emoted"
#define FINGER_D                "/adm/daemons/fingerd"
#define FTP_D           "/adm/daemons/ftpd"
#define INQUIRY_D               "/adm/daemons/inquiryd"
#define LOGIN_D         "/adm/daemons/logind"
#define MONEY_D         "/adm/daemons/moneyd"
#define NATURE_D                "/adm/daemons/natured"
#define PIG_D           "/adm/daemons/pigd"
#define PROFILE_D               "/adm/daemons/profiled"
#define RANK_D          "/adm/daemons/rankd"
#define SECURITY_D      "/adm/daemons/securityd"
#define UPDATE_D                "/adm/daemons/updated"
#define VIRTUAL_D               "/adm/daemons/virtuald"
#define WEAPON_D                "/adm/daemons/weapond"


// End of appendence
#define CLASS_D(x)      ("/kungfu/class/" + x)
#define SKILL_D(x)      ("/kungfu/skill/" + x)
#define CONDITION_D(x)  ("/kungfu/condition/" + x)

// Clonable/Non-inheritable Standard Objects
#define COIN_OB         "/clone/money/coin"
#define CORPSE_OB               "/clone/misc/corpse"
#define GOLD_OB         "/clone/money/gold"
#define LOGIN_OB                "/clone/user/login"
#define MASTER_OB               "/adm/single/master"
#define MAILBOX_OB      "/clone/misc/mailbox"
#define SILVER_OB               "/clone/money/silver"
#define SIMUL_EFUN_OB   "/adm/single/simul_efun"
#define USER_OB         "/clone/user/user"
#define VOID_OB         "/clone/misc/void"

// Inheritable Standard Objects
#define BANK            "/inherit/room/bank"
#define BULLETIN_BOARD  "/inherit/misc/bboard"
#define CHARACTER               "/inherit/char/char"
#define COMBINED_ITEM   "/inherit/item/combined"
#define EQUIP           "/inherit/misc/equip"
#define FORCE           "/inherit/skill/force"
#define HOCKSHOP                "/inherit/room/hockshop"
#define ITEM            "/inherit/item/item"
#define LIQUID          "/inherit/food/liquid"
#define MONEY           "/inherit/item/money"
#define NPC                     "/inherit/char/npc"
#define PILL            "/inherit/medicine/pill"
#define POWDER          "/inherit/medicine/powder"
#define ROOM            "/inherit/room/room"
#define SKILL           "/inherit/skill/skill"

// User IDs

#define ROOT_UID                "Root"
#define BACKBONE_UID    "Backbone"

// Features

#define F_ACTION                        "/feature/action.c"
#define F_ALIAS                 "/feature/alias.c"
#define F_APPRENTICE            "/feature/apprentice.c"
#define F_ATTACK                        "/feature/attack.c"
#define F_ATTRIBUTE             "/feature/attribute.c"
#define F_AUTOLOAD              "/feature/autoload.c"
#define F_CLEAN_UP              "/feature/clean_up.c"
#define F_COMMAND                       "/feature/command.c"
#define F_CONDITION             "/feature/condition.c"
#define F_DAMAGE                        "/feature/damage.c"
#define F_DBASE                 "/feature/dbase.c"
#define F_DEALER                        "/feature/dealer.c"
#define F_EDIT                  "/feature/edit.c"
#define F_EQUIP                 "/feature/equip.c"
#define F_FINANCE                       "/feature/finance.c"
#define F_FOOD                  "/feature/food.c"
#define F_PILL                  "/feature/pill.c"
#define F_LIQUID                        "/feature/liquid.c"
#define F_MASTER                        "/inherit/char/master.c"
#define F_MESSAGE                       "/feature/message.c"
#define F_MORE                  "/feature/more.c"
#define F_MOVE                  "/feature/move.c"
#define F_NAME                  "/feature/name.c"
#define F_SAVE                  "/feature/save.c"
#define F_SKILL                 "/feature/skill.c"
#define F_TEAM                  "/feature/team.c"
#define F_TREEMAP                       "/feature/treemap.c"
#define F_VENDOR                        "/feature/dealer.c"
#define F_SSERVER                       "/feature/sserver.c"
#define F_UNIQUE                        "/feature/unique.c"

// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#undef PROFILE_COMMANDS
