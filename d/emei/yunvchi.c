inherit ROOM;


void create()
{
        set("short", "��Ů��");
        set("long", @LONG
��Ů����һ�������ܴ�ĳ��ӣ���˵���겻��ɺԣ���ˮ�峺����ӳ
�ų��ϵ���Ů�壬��ɽ��ˮ����ɫ�������ˡ������Ͼ��Ǵ��������Ķ�ü
�ɵ������ˣ���˵��ü�ɷ�ɽ���ϣ�һ���οͲ�����ɽ�����Ի���С�ĵ�
�á�
LONG
        );

        set("exits", ([
		"southdown" : __DIR__"shifang",
		"eastup" : __DIR__"shanmen",
               ]));
	set("coor/x",-40);
	set("coor/y",-30);
	set("coor/z",50);
	set("coor/x",-40);
	set("coor/y",-30);
	set("coor/z",50);
	set("coor/x",-40);
	set("coor/y",-30);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}