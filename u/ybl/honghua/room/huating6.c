// by mayue

inherit ROOM;

void create()
{
        set("short", "练武场");
        set("long", @LONG
这里是红花会练武场，东边是一个沙坑，西边有一些木桩，是一个练武的
好地方，有几个红花会弟子正在这练功。
LONG
        );
//     set("outdoors", "honghua");

        set("exits", ([
                "south" : __DIR__"huating4",
                "east" : __DIR__"huayuan6",
        ]));
        set("objects", ([
                "/d/honghua/dizi" : 4,
        ]));
        setup();
//      replace_program(ROOM);
}

