inherit ROOM;

void create()
{
        set("short", "ǧ���");
        set("long", @LONG
���ڰڷ��������СС������,ÿ�����Ӷ���������������
�ţ�����֮�����������໥���ţ�������������װ�ŵ�����ǳ���Ҫ��
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"changlang3",
  "south" : __DIR__"dadian",
  "west" : __DIR__"changlang2",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/qu" : 1,
  __DIR__"npc/lao" : 1,
]));

        setup();
        replace_program(ROOM);
}
