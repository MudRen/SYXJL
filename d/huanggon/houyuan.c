inherit ROOM;

void create()
{
	set("short", "��͵��Ժ");
	set("long", @LONG
��������͵��Ժ��Ժ������Щ��ˡ�ǽ����һ��ˮ��(well)��
վ��ˮ�������¿���ֻ������ף����������ǻ��������̦��һ��
��ꤵ���һ������������ϵ��һ��ľͰ��������һ�����ȣ�ͨ�����
�
LONG
	);
        set("outdoors", "huanggon");
	set("resource/water", 1);
	set("exits", ([
		"east" : "/d/huanggon/zoulang1",
	]));

	set("coor/x",-70);
	set("coor/y",180);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

