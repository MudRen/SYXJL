// by mayue

inherit ROOM;

void create()
{
        set("short", "����ͤ");
        set("long", @LONG
������һ����԰�е�Сͤ�ӣ�������������ɫ���㡣ͤ����һ��һ������
ר����־�����塣
LONG
        );
//     set("outdoors", "honghua");

        set("exits", ([
                "south" : __DIR__"huating1",
                "west" : __DIR__"huayuan3",
//              "north" : __DIR__"huating3",
        ]));
        set("objects", ([
//                "/d/npc/guojing": 1,
        ]));
        setup();
//      replace_program(ROOM);
}

