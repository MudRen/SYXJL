inherit ROOM;

void create()
{
        set("short", "��ʤͤ");
        set("long", @LONG
���Ϸ�߱��ϣ���һ���˽�̨ͤ���Ӵ˿��Ϲ����ƣ�������ʯ��
����������ʤ�������顣��һ�ɾ�ɫ��⣨fengguang����
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wulao",
]));
    set("item_desc", ([
        "fengguang" : "�Ŀ�����֮�£��ף���ô�����Ϸ���������һ�㰵Ӱ��\n",
    ]));
        set("objects", ([
                __DIR__"npc/youke": 1,]) );

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
