// by mayue

inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
�����Ǻ컨�����䳡��������һ��ɳ�ӣ�������һЩľ׮����һ�������
�õط����м����컨�����������������
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

