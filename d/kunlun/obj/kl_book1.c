// kl book.c

inherit ITEM;

void create()
{
        set_name("���ǽ���<�Ͼ�>", ({ "book" }));
        set_weight(600);
        set("unit", "��");
        set("long", @LONG
                
����һ���������ǽ����������飬���ǽ��������������Դ��Ľ�����
��ѧ�׶����Ȿ����Ȼֻ���������ؽ��������ŵĹ��򣬵�������������
���㲻���ˣ��ʺϳ�ѧ�ߡ�
                
LONG );
        set("value", 100); 
        set("unique", 1);        set("skill", ([
                "name":"liangyi-jian", 
                "exp_required": 100,  
                "jing_cost"   :  20+random(20),  
                "difficulty" :  20,      
                "max_skill"  :  30, 
                                                                               
              ]) );
        setup();
}

string valid_study(object me, string arg)
{
        if ( me->query_skill("literate") < 10 )  {
                notify_fail("�㻹����ȥ��ʶ�����ְɡ�\n");
                return "";
        }
        if ( me->query_skill("liangyi-jian", 1) > 30 ) {
                notify_fail("�Ȿ�������ԣ�ʵ����̫��ǳ�ˡ�\n");
                return "";
        }

        write("�������۾���ϸϸ���Ķ������ǽ��ס��ϵ�˵����\n");

 return "liangyi-jian";
 
}


