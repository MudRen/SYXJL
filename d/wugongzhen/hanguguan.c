//hanguguan.c

inherit  ROOM;

void  create  ()
{
        set("short",  "���ȹ�");
        set("long",  @LONG
������ǹź��Źء���������ɽ���������򣬹�����С�����ǿ��
һ��֮�أ��ƹض������������Զ�������ɨ���£�������Ϊ���ݴˣ�
���ɹ����˿��أ���������ʤ֮������������������Ҳ���ڴ���������
���¾���ǧ�����£��������ж�������
LONG);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "east"  :  __DIR__"road1",
                "west"  :  __DIR__"daguandao2",
        ]));
        set("outdoors",  1);
        set("no_clean_up", 0);
        set("coor/x",-40);
	set("coor/y",130);
	set("coor/z",0);
	set("coor/x",-40);
	set("coor/y",130);
	set("coor/z",0);
	set("coor/x",-40);
	set("coor/y",130);
	set("coor/z",0);
	set("coor/x",-40);
	set("coor/y",130);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}


