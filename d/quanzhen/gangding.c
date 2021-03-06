// Room:gaongding.c 冈顶

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "冈顶");
	set("long", @LONG
迎面是一座庙宇，庙门横额写着“普光寺”三个大字，庙外有几个扫地
僧人，神情极其冷淡。庙外松树下有一排石凳，供游人歇脚。松树后有一块
石碑（shibei)，长草遮掩，依稀露出“长春”二字。往西就是终南山脚。
LONG
	);

	set("exits", ([ 
	     "southdown" : __DIR__"sgroad2",
	     "west" : __DIR__"shanjiao",
]));
	
        set("no_clean_up", 0);
        set("outdoors", "quanzhen" );
        set("item_desc",([
		"shibei"	:	"\n\t\t\t石碑上有首诗：\n\n\n" 
					"\t\t∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷\n"
					"\t\t∷　　　　　　　　　　　　　　        ∷∷\n"
                                  "\t\t∷    天苍苍兮临下土，胡为不救万灵苦？∷∷\n"
				       "\t\t∷　　　　　　　　　　　　　　        ∷∷\n"
                                  "\t\t∷万灵日夜相凌迟，饮气吞声死无悟。仰天∷∷\n"
	 	                    "\t\t∷　　　　　　　　　　　　　　        ∷∷\n"
                 	       	"\t\t∷大叫天不应，一物细琐枉劳形。安得大千∷∷\n"
					"\t\t∷　　　　　　　　　　　　　　　      ∷∷\n"
					"\t\t∷复混沌，免教造物生精灵。　          ∷∷\n"
					"\t\t∷　　　　　　　　　　　　　　        ∷∷\n"
					"\t\t∷　                          长春子  ∷∷\n"
					"\t\t∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷\n\n\n",
							
		]));
          

        setup();
        replace_program(ROOM);
}
