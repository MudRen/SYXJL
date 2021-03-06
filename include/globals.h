// globals.h
// this file will be automatically included by the driver

#define SAVE_EXTENSION __SAVE_EXTENSION__
#ifndef __SENSIBLE_MODIFIERS__
#define protected static
#define nosave static
#endif

//email daemon
#define REGROOM "/inherit/room/regroom"
#define EMAIL_D "/adm/daemons/emaild"
#define USERS   "/adm/etc/users"
#define IDUSER  "/adm/etc/iduser"
#define REGROOM "/inherit/room/regroom"
#define EMAIL_D "/adm/daemons/emaild"

#define TOPTEN_WUXUE     "/topten/wuxue.txt"
#define TOPTEN_RICH 	"/topten/rich.txt"
#define TOPTEN_PKER     "/topten/pker.txt"
#define TOPTEN_EXP     "/topten/exp.txt"
#define TOPTEN_MUDAGE      "/topten/mudage.txt"
#define WUXUE_B "	鹿鼎记TOP TEN十大武学高手排行榜"
#define MUDAGE_B "	鹿鼎记TOP TEN十大老不死排行榜"
#define RICH_B "	鹿鼎记TOP TEN十大富人排行榜"
#define PKER_B "	鹿鼎记TOP TEN十大杀人狂排行榜"
#define EXP_B  "	鹿鼎记TOP TEN十大EXP高手排行榜"
#define TOPTEN_D		"/adm/daemons/toptend"

#define TOPTEN_SOURCE       "/topten/source"
#define TOPTEN_DIR       "/topten/"
#define TOPTEN_FILE       "/topten/topten_file"
#define TOP_NAME       0
#define TOP_PROP       1
#define TOP_NAME_PROP       10
#define TOP_ID_NAMES       100
#define TOP_ID_PROPS       200
#define TOP_IDS       300

// Important directories
#define INC_DIR         "/include/"
#define COMMAND_DIR     "/cmds/"
#define CONFIG_DIR      "/adm/etc/"
#define DATA_DIR        "/data/"
#define HELP_DIR        "/help/"
#define LOG_DIR         "/log/"
#define STORY_DIR       "/adm/daemons/story/"
#define BACKUP_DIR      "/backup/"
#define TEMP_DIR        "/temp/"
#define DUMP_DIR        "/dump/"
// Daemons
#define ALIAS_D         "/adm/daemons/aliasd"
#define BAN_D           "/adm/daemons/band"
#define CHANNEL_D       "/adm/daemons/channeld"
#define CHAR_D          "/adm/daemons/chard"
#define CHINESE_D       "/adm/daemons/chinesed"
#define COMBAT_D        "/adm/daemons/combatd"
#define COMMAND_D       "/adm/daemons/commandd"
#define CONVERT_D       "/adm/daemons/convertd"
#define EMOTE_D         "/adm/daemons/emoted"
#define FINGER_D        "/adm/daemons/fingerd"
#define FTP_D           "/adm/daemons/ftpd"
#define INQUIRY_D       "/adm/daemons/inquiryd"
#define LANGUAGE_D      "/adm/daemons/languaged"
#define LOGIN_D         "/adm/daemons/logind"
#define MONEY_D         "/adm/daemons/moneyd"
#define NATURE_D        "/adm/daemons/natured"
#define PIG_D           "/adm/daemons/pigd"
#define PROFILE_D       "/adm/daemons/profiled"
#define RANK_D          "/adm/daemons/rankd"
#define SECURITY_D      "/adm/daemons/securityd"
#define TASK_D          "/adm/daemons/taskd"
#define UPDATE_D        "/adm/daemons/updated"
#define VIRTUAL_D       "/adm/daemons/virtuald"
#define WEAPON_D        "/adm/daemons/weapond"
#define BACKUP_D        "/adm/daemons/backupd"
#define STORY_D         "/adm/daemons/storyd"
#define NPC_D           "/adm/daemons/npcd"
//here is the skill model
#define SKILL_MODEL_UNARMED    "/maxim/skill_model_unarmed.c"
#define SKILL_MODEL_WEAPON     "/maxim/skill_model_weapon.c"
#define SKILL_MODEL_DEFAULT    "/maxim/skill_model_default.c"


// Added for questing
// by Hop, 1997.05.16
#define QUEST_D(x)      ("/quest/quest/qlist" + x)
// End of appendence
#define CLASS_D(x)      ("/kungfu/class/" + x)
#define SKILL_D(x)      ("/kungfu/skill/" + x)
#define CONDITION_D(x)  ("/kungfu/condition/" + x)

// Clonable/Non-inheritable Standard Objects
#define COIN_OB         "/clone/money/coin"
#define CORPSE_OB       "/clone/misc/corpse"
#define GOLD_OB         "/clone/money/gold"
#define THCASH_OB       "/clone/money/thousand-cash"
#define LOGIN_OB        "/clone/user/login"
#define MASTER_OB       "/adm/single/master"
#define MAILBOX_OB      "/clone/misc/mailbox"
#define SILVER_OB       "/clone/money/silver"
#define SIMUL_EFUN_OB   "/adm/single/simul_efun"
#define USER_OB         "/clone/user/user"
#define VOID_OB         "/clone/misc/void"

// Inheritable Standard Objects
#define BANK            "/inherit/room/bank"
#define BULLETIN_BOARD  "/inherit/misc/bboard"
#define WIZ_BULLETIN_BOARD  "/inherit/misc/wiz_bboard"
#define CHARACTER       "/inherit/char/char"
#define FIGHTER         "/inherit/char/fighter"
#define COMBINED_ITEM   "/inherit/item/combined"
#define EQUIP           "/inherit/misc/equip"
#define FORCE           "/inherit/skill/force"
#define HOCKSHOP        "/inherit/room/hockshop"
#define ITEM            "/inherit/item/item"
#define LIQUID          "/inherit/food/liquid"
#define MONEY           "/inherit/item/money"
#define NPC             "/inherit/char/npc"
#define PILL            "/inherit/medicine/pill"
#define POWDER          "/inherit/medicine/powder"
#define ROOM            "/inherit/room/room"
#define SKILL           "/inherit/skill/skill"
#define NPC_SAVE        "/inherit/char/npcsave"
#define SELL_SALT   "/inherit/char/sell_salt"
#define POISON          "/inherit/condition/poison"
#define POISON_INSECT   "/inherit/char/insect"
#define CHALLENGER      "/inherit/char/challenger"
#define SNAKE           "/inherit/char/snake"
// User IDs

#define ROOT_UID        "Root"
#define BACKBONE_UID    "Backbone"

// Features

#define F_ACTION                "/feature/action.c"
#define F_ALIAS                 "/feature/alias.c"
#define F_APPRENTICE            "/feature/apprentice.c"
#define F_ATTACK                "/feature/attack.c"
#define F_ATTRIBUTE             "/feature/attribute.c"
#define F_AUTOLOAD              "/feature/autoload.c"
#define F_CLEAN_UP              "/feature/clean_up.c"
#define F_COMMAND               "/feature/command.c"
#define F_CONDITION             "/feature/condition.c"
#define F_DAMAGE                "/feature/damage.c"
#define F_DBASE                 "/feature/dbase.c"
#define F_DEALER                "/feature/dealer.c"
#define F_EDIT                  "/feature/edit.c"
#define F_ENCODING              "/feature/encoding.c"
#define F_EQUIP                 "/feature/equip.c"
#define F_FINANCE               "/feature/finance.c"
#define F_FOOD                  "/feature/food.c"
#define F_LIQUID                "/feature/liquid.c"
#define F_MASTER                "/inherit/char/master.c"
#define F_MESSAGE               "/feature/message.c"
#define F_MORE                  "/feature/more.c"
#define F_MOVE                  "/feature/move.c"
#define F_NAME                  "/feature/name.c"
#define F_PAWN                  "/feature/pawn.c"
#define F_SAVE                  "/feature/save.c"
#define F_SKILL                 "/feature/skill.c"
#define F_TEAM                  "/feature/team.c"
#define F_TREEMAP               "/feature/treemap.c"
#define F_VENDOR                "/feature/dealer.c"
#define F_SSERVER               "/feature/sserver.c"
#define F_UNIQUE                "/feature/unique.c"
#define F_VENDOR_SALE           "/feature/vendor_sale.c"

// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#undef PROFILE_COMMANDS

