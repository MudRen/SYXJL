//HSQTAN6.C

inherit ROOM;

void create()
{
	set("short", "��̶");
	set("long", @LONG
�����ˮֻ���������վ��ˮ�У��Ըо������
�������𣬾��ò�ɢ��
LONG
	);

	set("exits", ([
		"up" : __DIR__"hsq1",
		"west" : __DIR__"hsqtan5",
	]));

//	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}






	

