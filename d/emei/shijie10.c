inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
������ͨ������ɽ��ʯ�ף�һ��������ʯ���������죬����û�о�ͷ��
�ģ��ϵĽ����������������;�������֣�������С����·���򣬻��ж�
ü��Ů����׼ҵ�������������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "northeast" : "/d/wudang/wdroad8",
  "west" : __DIR__"shijie11",
]));
	set("no_clean_up", 0);

	set("coor/x",-40);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",-40);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",-40);
	set("coor/y",-100);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
