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
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"yiting",
  "west" : __DIR__"dadian",
  "south" : __DIR__"houdian",
  "north" : __DIR__"changlang4",
]));

        setup();
        replace_program(ROOM);
}
