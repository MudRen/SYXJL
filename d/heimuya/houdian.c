inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�����޴�����ڵ������λε����򣬵��аڷ�һ�Ŵ��������԰�����
��ʽ���ӣ�һ����֪�������ǽ�����Ҫ��������ı�ߵĵط���
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"laofangrk",
  "north" : __DIR__"changlang6",
  "west" : __DIR__"changlang5",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/zhou" : 1,
  __DIR__"npc/wu" : 1,
]));

        setup();
        replace_program(ROOM);
}