// pubu.c

inherit ROOM;

void init();
int do_swim();

void create()
{
	set("short", "ɽ���ٲ�");
	set("long", @LONG
������һ��Ͽ�ȣ�ÿ���꼾ɽ�鱬��ʱ���γ���һ��εΪ׳�۵��ٲ���
��˵�������������������������ɾ��������������ġ�������ȥ�ȿգ�
ֻʣ�¿��ȵ�ɽ�Ⱥͱ��ڵĺ�ˮ(hongshui)��
LONG
);
	set("exits", ([ /* sizeof() == 1 */
		"northwest" : __DIR__"shaluo",
	]));

	set("outdoors","huashan");
        set("coor/x",60);
	set("coor/y",120);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",120);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",120);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",120);
	set("coor/z",0);
	setup();
        set("resource/water", 1);
	set("no_clean_up", 0);

	set("item_desc", ([
		"hongshui" : "����һ�ɱ��ڲ�Ϣ�ĺ�ˮ��ˮ�������и������ڷ��⣬���㶨\n
����ϸһ����������ֻ������ˮ�淴����չ����\n",
	]));

	set("coor/x",60);
	set("coor/y",120);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",120);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",120);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",120);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
void init()
{
	add_action("do_swim","swim");
}
int do_swim()
{
	object me = this_player();
	message_vision("$Nһ�����������ٲ��У�����\n",me);
	me->move("/u/smok/lowriver");
	return 1;	
}