// Room: /d/city/shuyuan.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
	��������Ժ�Ľ��ã�����������һ����Ⱦ��һλׯ���������������̫ʦ
���Ͻ�ѧ���Ǿ��ǵ�������������ˡ�������������������ѧ��ѧ����һ�Ź��ⰻ
Ȼ���鰸������������ǰ�棬���ϰ��ż��������˵���װ�鼮���������������һ
�����(shujia)�����ڶ��������ʯ�̣������Ժ��ʷ���ƾá�ֵ��һ�����Ƕ��
����ǰ��ڵ�ѧ��(xuegui)��
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "xuegui" : "�ս����������տ���Ŀ��ҳ��
ͨ��ʱ�������ζ�����ʫ����
���������ʣ���ΰ�ʱ���ꡣ
ҹ���Խ���������Ҫ������

��ѧ���ѧ����ʮ��
",
]));
	set("exits", ([ /* sizeof() == 2 */
                "north" : "/quest/poem/yard",
                "south" : __DIR__"dongdajie1",
//	"up" : "/u/qingp/xxci",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhu" : 1,
]));
        set("no_fight",1);
        set("no_yun",1);
        set("no_steal",1);
        set("no_beg",1);
	set("no_clean_up", 0);

	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
