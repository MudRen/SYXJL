// room: /kunlun/lianwu1.c

inherit ROOM;



void create()

{

        set("short", "练武场");

        set("long", @LONG

这里是功力较低的昆仑弟子操练剑法拳脚的地方，场中有常见的沙袋，木

桩等物。几名年轻的弟子正在辛勤地练功，昆仑派以剑术见长, 但也十分重视

拳剑的基本功夫，故此入门弟子多在此打熬身体, 等待有一定根底后方能得授

上乘武功。

LONG

        );

        set("exits", ([

                "east" : __DIR__"qianting",

        ]));

        set("objects", ([ /* sizeof() == 1 */

                "/d/kunlun/npc/muren" :   2,

         ]));        setup();

        replace_program(ROOM);

}



