inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һ·�߹���ֻ��������������ʿ�������ԣ����и�ͦһ�����λεĳ�����
����ƽ�٣�����֮�˶�Ҫ������ͷ���������ٱ�������ֻҪ��һ��ͻȻ
���䣬�㲻�������촦��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"dadian",
  "south" : __DIR__"fengleitang",
  "north" : __DIR__"baihutang",
  "west" : __DIR__"qiandian",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/chou" : 1,
  __DIR__"npc/shizhe" : 2,

]));

        setup();
        replace_program(ROOM);
}
