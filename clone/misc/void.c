// void.c (re-created after Elon screwed it up on 07-24-95)



inherit ROOM;



void create()

{

	set("short","������԰");
	set("long",@LONG	

������Ǵ�˵�е� VOID -- �������ʦ��������԰. �㿴������һƬ

��ãã��, ��һ���������ð��һֻ���, �ݸ���һ�ޡ��ɿڿ��֡�(tm), 

Ȼ��վ��һ�Ժ�а���Ц��. �ֹ���һ��, һֻ���������˹���, һ���ı�

����ֻ��첢��������������ƿ����, ��Ц������ʹ�����ǰ��ʧ��.

��ҡҡͷ, ���ֵط����ǲ�Ҫ��̫�õĺ�.

LONG

	);



	set("exits", ([

		"down" : "/d/city/zuixianlou",

	]));



        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        set("no_yun",1);
	setup();

	replace_program(ROOM);

}

