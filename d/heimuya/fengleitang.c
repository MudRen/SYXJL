inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�˴������½̷������������ճ�����֮�أ����ڲ�û���ر�İ��裬ֻ
�ڴ��ðڷ���һ��̫ʦ�Ρ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"changlang5",
  "north" : __DIR__"changlang",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tong" : 1,
]));

        setup();
        replace_program(ROOM);
}
