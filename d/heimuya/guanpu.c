// baichi.c

inherit ROOM;

void create()
{
        set("short", "����ͤ");
        set("long", @LONG
�����ٲ����������ͤ�����Ǿ��õ�����ʥ�أ�վ�ڴ˴����ɽ���
�����٣��羵�İ���Ȫ���޲������۵ס�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yupingpu",
  "northup" : __DIR__"moyun",
]));
        set("objects", ([
                __DIR__"npc/youke": 1,]) );

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
 
