//Room: /d/dali/cangshan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","��ɽ");
        set("long",@LONG
��ɽ֮��ʢ����ʯ�����ƴ���ʯ���������ʯ����ʯ����ʯ��ʯ
��ϸ�壬ɫ�ʷḻ���вʻ���ˮī�����ҡ�ѩ�׵�Ʒ�֡�ˮī��Ϊϡ
�У��ʻ������ص㣬��������������ͣ�������ɽ������������֮�Σ�
��̬��ǧ��������ɣ�Ϊ������������ʯ�Ǿ����Ľ������ϣ�������
ǽ�̵أ����������������ˮ������������ѩ��ʯ������԰��񣬾�
Ө�ɰ��������֬���ǵ�̡��滭�ĺò��ϡ�ʯ���Բ��ڴ�����������
�������·����ֻ�ʯ�Գƴ���ʯ����������Ҳ���ʯ���������¡�
LONG);
        set("outdoors", "dali");
        set("exits",([ /* sizeof() == 1 */
            "north"     : __DIR__"shilin",
            "east"      : __DIR__"hongsheng",
            "southwest" : __DIR__"xiaguan", 
            "northdown" : __DIR__"dadao1",        ]));
        set("no_clean_up", 0);
        set("coor/x",-10);
	set("coor/y",-50);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-50);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-50);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-50);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}