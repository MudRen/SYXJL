//jingdun.c ���

inherit SKILL;

void create() { seteuid(getuid()); }

void init()
{
    add_action("do_jingdun", "jingdun");
}

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        if( (int)me->query("dex") < 24 ) 
           return  notify_fail("������Բ��ʺ�ѧϰ����!\n" ) ;
	return 1;
}

