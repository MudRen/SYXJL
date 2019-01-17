// mei_po.c
// modify by ronger 12/98

#include <ansi.h>

inherit NPC;

string marry();
string unmarry();

void create()
{
        set_name("ý��", ({ "mei_po" }) );
        set("title", "����");
        set("gender", "Ů��" );
        set("age", 43);
        set("long",
                "һλ�����ܸɵ���ý��\n");
        set("combat_exp", 100000);
        set("attitude", "friendly");
        set("inquiry", ([
                "��Լ" : "�ǰ�... ����Ϳ��Ե޽�ͽ����Լ",
        ]) );
        set_skill("literate", 100);
        set_skill("dodge", 500);
        set_skill("unarmed", 300);
        setup();
        add_money("gold", 5);
	carry_object("d/city/obj/cloth")->wear();
}

void init()
{
        ::init();

        add_action("do_marry", "marry");
        add_action("do_unmarry", "unmarry");
        add_action("do_marry", "jiehun");
        add_action("do_unmarry", "lihun");
//	add_action("do_name","��");
}

int do_marry(string arg)
{
	object obj, me, old_target, card, *all, book1, book2;

	me = this_player();
	all = users();

	if ( (string)me->query("gender") == "����")
		return notify_fail("���޸����ԣ�����������\n");

	if (((int)me->query("age") < 18) && (me->query("gender") == "����")
		||((int)me->query("age") < 16) && (me->query("gender") == "Ů��"))
		return notify_fail("�����ڻ����ᣬ�Ժ���˵�ɣ�\n");

	if (me->is_busy())
		return notify_fail("ý��˵������������æ���ء�\n");

	if( me->is_fighting(this_object()) )
	{
		if( !this_object()->is_killing(me) )
			this_object()->kill_ob(me); 
		return notify_fail("ý��˵������������ȥ����ɻ飡\n"); 
	}

	if( this_object()->is_fighting() )
		return notify_fail("ý��˵����û����������˵�����\n");

	if( !living(this_object()) )
		return notify_fail("�㻹������취��ý�ž��Ѱɡ�\n"); 

	if( me->is_fighting() )
		return notify_fail("ý��˵�����ٺ٣����Ȼ������������������˵�ɣ�\n");

//	if( !environment() || base_name(environment()) != query("startroom"))
//		return notify_fail("ý��˵�������Ǳ�Ǹ��������һ�µ�����ׯ�����Ұɡ�\n");

	if( (string)me->query("class")=="bonze" ) 
		return notify_fail("ý��Ц������������ô������Ҳ�뿪ɫ������?\n");

  	if( me->query("unmarried") > 5 )
		return notify_fail("ý���������۾�˵�������רҵ����\n");

	if(!arg || !objectp(obj = present(arg, environment(me)))
		|| !find_player(arg) )
		return notify_fail("ý��˵���������˭ϲ����Ե��\n");

	if( me->query_temp("pending/pro") )
		return notify_fail("ý��˵������Ļ������ڽ����С�\n");

	if( obj->query_temp("pending/pro") )
		return notify_fail("ý��˵������������˽�����\n");

	if( !obj->is_character() )
		return notify_fail("ý��˵�������ⲻ�����Լ�������\n");

	if( (string)obj->query("class")=="bonze" ) 
		return notify_fail(
                "ý��Ц�����������˼ҿ��ǳ����ˣ�����˼ҿ���Ц�ˡ�\n");

	if( mapp( me->query("couple") ) )
	{
		if ( me->query("couple/have_couple") )
		{
			if ( obj == present((string)me->query("couple/couple_id"), environment(me)) )
				return notify_fail("ý��˵�������Ǳ������Ƿ���ѽ��\n");
			if ((string)me->query("gender") == "Ů��") 
				return notify_fail("ý��˵�������Ѿ����з�֮���ˣ����ﲻ�����ػ�ġ�\n");
			else
				return notify_fail("ý��˵�������Ѿ����и�֮���ˣ����ﲻ�����ػ�ġ�\n");
		}
	}

	if( mapp( obj->query("couple") ) )
	{
        	if( obj->query("couple/have_couple") )
		{
			if((string)obj->query("gender") == "Ů��") 
				return notify_fail(
                    "ý��˵������ϧ���Ѿ����з�֮���ˣ����ﲻ�����ػ�ġ�\n");
			else
				return notify_fail(
                    "ý��˵������ϧ���Ѿ����и�֮���ˣ����ﲻ�����ػ�ġ�\n");
		}
	}

	if( !living(obj) )
		return notify_fail("ý��˵����" + obj->name() + "�޷����㹲������\n"); 

	if((string)obj->query("gender") == (string)me->query("gender"))
		return notify_fail("ý��˵�����㲻��" + RED"AIDS"NOR + "��\n");

	if(obj == me)
		return notify_fail("ý��˵�������ⲻ�����Լ�������\n");

	if( !userp(obj) )
		return notify_fail("ý��˵�����Բ�����ֻ��Ȣ��ҡ�\n");

	if( (object)obj->query_temp("pending/marry")!=me )
	{
		if ((string)obj->query("gender") == "Ů��") 
			message_vision(MAG "\n$N����$n˵������Ը��޸�����\n\n"NOR, me,obj);
		else
			message_vision(MAG "\n$N����$n˵������Ը��Ȣ����\n\n"NOR, me,obj);

		if( objectp(old_target = me->query_temp("pending/marry")) && old_target != obj )
			tell_object(old_target, YEL + me->name() + 
                        "ȡ���˺��������ͷ��\n" NOR);
           
		me->set_temp("pending/marry", obj);

		if ((string)obj->query("gender") == "Ů��") 
			tell_object(obj, MAG "�����Ը��޸���������Ҳ��" + me->name()
			+ "("+(string)me->query("id") + ")"+ "��һ�� marry ָ�\n" NOR);
		else
			tell_object(obj, MAG "�����Ը��Ȣ��������Ҳ��" + me->name() + 
			"("+(string)me->query("id") + ")"+ "��һ�� marry ָ�\n" NOR);

                write(MAG  
                        "�����㼱�����������������˵ͬ��...\n" NOR);
                return 1;
	}

	message_vision(MAG "\n$N����$n˵������Ը�⣡\n\n"NOR, me,obj);           
	message_vision(MAG "ý��˵����$N��$n�����ڿ�ʼ������! \n" NOR, obj, me);
	message_vision(MAG "ý��˵�������������ǵ������ˡ�\n\n" NOR,obj, me);
	message_vision(MAG "ý�ź������� ���ඣ�\n" NOR,obj, me);

	me->set_temp("pending/pro", 1);
	obj->set_temp("pending/pro", 1);

	me->set("couple/couple_name",(string)obj->name());
	me->set("couple/couple_id",obj->query("id"));

	obj->set("couple/couple_name",(string)me->name());
	obj->set("couple/couple_id",me->query("id"));

	card=clone_object("/d/city/obj/marry_card");
	card->set("name","���"+obj->query("name")+"�Ľ��֤");
	card->move(me);
	card=clone_object("/d/city/obj/marry_card");
	card->set("name","���"+me->query("name")+"�Ľ��֤");
	card->move(obj);
	say("ý�ŵݸ�"+obj->query("name")+"��"+me->query("name")
		+"һ��һ�Ž��֤��.\n");

	book1=new("/d/city/obj/dienianhua-book");
	book2=new("/d/city/obj/qiuge-book");
	if ((string)obj->query("gender") == "Ů��") {
		book1->move(obj);
		book2->move(me);
	}

	else {
		book1->move(me);
		book2->move(obj);
	}

        message("shout", HIC "��¹���ǡ���" + HIR + "����" + me->query("name") + "��"
	+ obj->query("name") + "ϲ������\n"+"\n"+
         "
	         ��        �� 
	    ����������������������
	         ��        ��
	     ��������������������
	       ������    ������
	       ��  ��    ��  ��
	       ������    ������
	        ����      ����
	   ������������������������
	       ������    ������
	       ��  ��    ��  ��
	       ������    ������\n"             
          NOR,users());
	if ((string)obj->query("gender") == "Ů��")
	{
		me->set("couple/couple_gender", "����");
		obj->set("couple/couple_gender", "�Ϲ�");
	}
	else
	{
		obj->set("couple/couple_gender", "����");
		me->set("couple/couple_gender", "�Ϲ�");
	}
          
	me->add("married", 1);
	me->set("couple/have_couple",1);
	obj->add("married", 1);
	obj->set("couple/have_couple",1);
	me->set_temp("pending/pro", 0);
	obj->set_temp("pending/pro", 0);

	return 1;
}

int do_unmarry(string arg)
{
	object me, obj, *inv;

	int i;
	me = this_player();       

	if (me->is_busy())
		return notify_fail("ý��˵������������æ���ء�\n");

	if( me->is_fighting(this_object()) )
	{
		if( !this_object()->is_killing(me) )
			this_object()->kill_ob(me); 
		return notify_fail("ý��˵��������������ȥ���䣡\n");
	}

	if( this_object()->is_fighting() )
		return notify_fail("ý��˵����û����������˵�����\n");

	if( !living(this_object()) )
		return notify_fail("�㻹������취��ý�ž��Ѱɡ�\n"); 

	if( me->is_fighting() )
		return notify_fail("ý��˵�����ٺ٣����Ȼ������������������˵�ɣ�\n");

	if( !environment()||base_name(environment()) != query("startroom") )
		return notify_fail("ý��˵�������Ǳ�Ǹ��������һ�µ�����ׯ�����Ұɡ�\n");

	if( !mapp( me->query("couple") ) || !me->query("couple/have_couple") ) 
	{
		if ((string)me->query("gender") == "Ů��") 
			return notify_fail("ý��˵�����㻹δ���ɷ򰡡�\n");
		else
			return notify_fail("ý��˵�����㻹δ�����Ӱ���\n");
	}

	if( !objectp(obj = present((string)me->query("couple/couple_id"), environment(me)))
                 || !find_player(me->query("couple/couple_id")) )
		return notify_fail("ý��˵������İ������ڲ��ڳ���\n");
	if( (object)obj->query_temp("pending/unmarry")!=me )
	{
		message_vision(MAG "\n$N����$n˵�����Բ��𣬲����Ҳ����㣬ֻ��... ���Ǻþۺ�ɢ������?
\n\n"NOR, me,obj);           
		me->set_temp("pending/unmarry", obj);

		if ((string)obj->query("gender") == "Ů��") 
			tell_object(obj, MAG "����㲻�����ˣ�����Ҳ��" 
                       	+me->name() + "("+(string)me->query("id")+
                       	")"+ "��һ�� unmarry ָ�\n" NOR);
		else
			tell_object(obj, MAG "����㲻�����ˣ�����Ҳ��" 
                       	+me->name() + "("+(string)me->query("id")+
                       	")"+ "��һ�� unmarry ָ�\n" NOR);

		write(MAG "���������ȴ�����İ��µĻش�...\n" NOR);
		return 1;
	}
       
	message_vision(MAG "\n$N����$n˵������Ȼ��Ե�����Ǿ͸��߸���·�ɡ�\n\n"NOR, me,obj);           
	message_vision(MAG "ý��˵����$N��$n�����ڿ�ʼ���Ƿ���! \n" NOR, obj, me);

	CHANNEL_D->do_channel(this_object(), "chat",
	sprintf( "��ϧ%s��%s��һ���������ַ�... ��Ը�����档\n", me->name(), obj->name()));
        
	me->add("unmarried", 1);
	me->set("couple/have_couple",0);

	obj->add("unmarried", 1);
	obj->set("couple/have_couple",0);

	inv=all_inventory(me);
	for(i=0;i<sizeof(inv);i++)      
	{
		if(inv[i]->query("id")=="jiehunzheng") 
		{
			destruct(inv[i]);
		}
	}
	inv=all_inventory(obj);
	for(i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->query("id")=="jiehunzheng")
		{
			destruct(inv[i]);
		}
	}

	return 1;
}
/*
int do_name(string arg)
{
	object me, obj;
	string act;

	me = this_player();       

	if (me->is_busy())
		return notify_fail("ý��˵������������æ���ء�\n");

	if( me->is_fighting(this_object()) )
	{
		if( !this_object()->is_killing(me) )
			this_object()->kill_ob(me); 
		return notify_fail("ý��˵������������ȥ����ɻ飡\n");
	}

	if( this_object()->is_fighting() )
		return notify_fail("ý��˵����û����������˽�����\n");

	if( !living(this_object()) )
		return notify_fail("�㻹������취��ý�ž��Ѱɡ�\n"); 

	if( me->is_fighting() )
		return notify_fail("ý��˵�����ٺ٣����Ȼ������������������˵�ɣ�\n");

	if( !environment()||base_name(environment()) != query("startroom") )
		return notify_fail("ý��˵�������Ǳ�Ǹ��������һ�µ�����ׯ�����Ұɡ�\n");

	if( !me->query_temp("pending/pro") )
		return notify_fail("ý��Ц�����������㷸ʲôɵѽ��\n");

	if( !objectp(obj = present((string)me->query("couple/couple_id"), environment(me)))
		|| !find_player(me->query("couple/couple_id")) )
		return notify_fail("ý��˵������İ��������뿪�ˣ�����ֻ���жϡ�\n");

	if(!arg && !(me->query_temp("pending/pro")==1 && arg=="���")
		&& !(me->query_temp("pending/pro")==2 && arg=="����")
		&& !(me->query_temp("pending/pro")==3 && arg==(string)me->query("couple/couple_name")))
		return notify_fail("ý��Ц�������Ұ�ʲôѽ��\n");

	obj->set_temp("pending/pro", me->query_temp("pending/pro"));
	{
		if( (string)obj->query_temp("pending/act")!=arg )
		{
			tell_object(obj, MAG"��İ��������ź����" + arg + "��...\n" NOR);
			write(MAG "���������ȴ�����İ���...\n" NOR);
			me->set_temp("pending/act", arg);
			return 1;
		}
	}
       
	message_vision(MAG "ý��˵����$N��$n�������Ƿ�����! \n" NOR, obj, me);
	CHANNEL_D->do_channel(this_object(), "chat",
		sprintf( "��ϲ%s��%s��һ�����ϲ����Ե��\n", me->name(), obj->name()));
        
	me->add("married", 1);
	me->set("couple/have_couple",1);
	obj->add("married", 1);
	obj->set("couple/have_couple",1);

	me->set_temp("pending/pro", 0);
	obj->set_temp("pending/pro", 0);
	
	return 1;
}
*/
