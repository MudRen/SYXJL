// force_book.c �ڹ��ķ�

inherit ITEM;

void create()
{
        set_name("�컨�ķ�", ({ "shu", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ����װ�飬�����ź컨����ڹ��ķ���\n");
                set("value", 0);
		set("material", "paper");
		set("skill", ([
                        "name": "force",        // name of the skill
         "exp_required": 0,      // minimum combat experience required
                        "jing_cost":    0,     // jing cost every time study this
                        "difficulty":   0,     // the base int to learn this skill
                        "max_skill":    500      // the maximum level you can learn
		]) );
	}
}
        set("item_desc", ([

                "table" : "����һ�����ʯ��ɵ�ʯ�����������Щ��ֵ�ͼ�Ρ�\n",

        ]));



        setup();

}



void init()

{

        add_action("do_study", "study");

}





int do_study(string arg)

{

        object me

        int    jing_cost






        if ( !arg || ( arg != table ) )

                return notify_fail(ʲô��\n)



        if ( (int)me->query_skill(literate, 1) < 1)

                return notify_fail(���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n)




        if((int)me->query(jing) < jing_cost)

                return notify_fail(�����ھ����޷����У�\n)



        me->add(jing, jing_cost)



        message_vision($N��ר���ж�ʯ���ϵĹŹ�ͼ�Ρ�\n, me)



        switch( random(5) ) 


        {

            case 0:

                if ( (int)me->query_skill(finger, 1) < 100)

                {

                        me->improve_skill(finger, me->query(int))

                        write(�����ʯ����ĥ��һ�ض����ƺ���ָ���е��ĵá�\n)

                        me->set_temp(stone_learned,1)

                }

            case 1:

                if ( (int)me->query_skill(claw, 1) < 100)

                {

                        me->improve_skill(claw, me->query(int))

                        write(�����ʯ����ĥ��һ�ض����ƺ���צ���е��ĵá�\n)

                        me->set_temp(stone_learned,1)

                }

            case 2:

                if ( (int)me->query_skill(strike, 1) < 100)

                {

                        me->improve_skill(strike, me->query(int))

                        write(�����ʯ����ĥ��һ�ض����ƺ����Ʒ��е��ĵá�\n)

                        me->set_temp(stone_learned,1)

                }

            case 3:

                if ( (int)me->query_skill(cuff, 1) < 100)

                {

                        me->improve_skill(cuff, me->query(int))

                        write(�����ʯ����ĥ��һ�ض����ƺ���ȭ���е��ĵá�\n)

                        me->set_temp(stone_learned,1)

                }

            case 4:

                if ( (int)me->query_skill(hand, 1) < 100)

                {

                        me->improve_skill(hand, me->query(int))

                        write(�����ʯ����ĥ��һ�ض����ƺ����ַ��е��ĵá�\n)

                        me->set_temp(stone_learned,1)

                }

        }



        if ( !me->query_temp(stone_learned) )

        {

                write(�����ʯ����ĥ��һ�ض�������������˵��̫��ǳ�ԣ�������˵�Ѻ��������ˡ�\n)

        }

        return 1

}


