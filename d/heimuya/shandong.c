inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����������ӯӯ��ס�ĵط����������յ�͵ƣ�����΢���ƹ⡣
������������ż���ʯ��ʯ������������һ��(ʯ��)��
���õü�֮���ӣ����Ǿ͵�ȡ���ɶ���ʯ��ӹ����ɣ�����
������п��������һ��ɽ��ȷʵ���ס�
LONG
        );
        set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/yingying" : 1,
]));
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shandong2",
  "north" : __DIR__"dashikuai",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
