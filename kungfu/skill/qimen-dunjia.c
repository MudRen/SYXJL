// hubo.c



//inherit ITEM;

inherit SKILL;



void create() { seteuid(getuid()); }



void init()

{

    add_action("do_dun","dun");

      add_action("do_yin","yin");

}



string type() { return "knowledge"; }



int valid_learn(object me) 

{

        if( (int)me->query("dex") < 24 ) 

           return  notify_fail("������Բ��ʺ�ѧϰ���Ŷݼ�֮��!\n" ) ;

	return 1;

}

