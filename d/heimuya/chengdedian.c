inherit ROOM;

void create()
{
        set("short", "�ɵµ�");
        set("long", @LONG
���аڷ���һ�Ŵ��������Ϸ������ķ��ı���ǽ�Ϲ������ֻ������õ�
ʮ�����ţ��Ա�һ��ľ��ͨ�����档
LONG
        );
        set("exits", ([ /* sizeof() == 5 */
  "east" : __DIR__"yaofang",
  "up" : __DIR__"changjingge",
  "south" : __DIR__"dadian",
  "north" : __DIR__"changlang2",
  "west" : __DIR__"zhuquetang",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/ji" : 1,
]));

        setup();
        replace_program(ROOM);
}
