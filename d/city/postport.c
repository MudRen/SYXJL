//room: /u/chen/shashou/postport.c
inherit ROOM;

void init();

void create()
{
	set("short","�ʼ���վ");
	set("long", @LONG
	�����ǻʼ���վ��ר�Ÿ�����ȫ�������������ż���һ��������Ų�վ��
һ�����У�һ����ͷ�ö�����ӡ�
LONG
	   );
	set("exits",([
           "south" : "/d/shaolin/xingbudatang",
	   ]));
	set("objects",([
                     "/quest/quest1/npc":1,
		]));

	set("no_fight", 1);
	set("no_yun", 1);
	set("no_steal", 1);
	set("coor/x",30);
	set("coor/y",150);
	set("coor/z",0);
	setup();
}
