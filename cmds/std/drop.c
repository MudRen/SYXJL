// drop.c

// writed by shadow



inherit F_CLEAN_UP;



int do_drop(object me, object obj);



void create() { seteuid(getuid()); }



int main(object me, string arg)

{

	object obj, *inv, obj2;

	int i, amount;

	string item;



	if(!arg) return notify_fail("��Ҫ����ʲô������\n");



	if(sscanf(arg, "%d %s", amount, item)==2)

	{

		if( !objectp(obj = present(item, me)) )

			return notify_fail("������û������������\n");

		if( stringp(obj->query("no_drop")) )

			return notify_fail( (string)obj->query("no_drop") );

		if( !obj->query_amount() )

			return notify_fail( obj->name() + "���ܱ��ֿ�������\n");

		if( amount < 1 )

			return notify_fail("����������������һ����\n");

		if( amount > obj->query_amount() )

			return notify_fail("��û����ô���" + obj->name() + "��\n");

		else

			if( amount == (int)obj->query_amount() )

				return do_drop(me, obj);

			else

			{

				obj->set_amount( (int)obj->query_amount() - amount );

				obj2 = new(base_name(obj));

				obj2->set_amount(amount);

				return do_drop(me, obj2);

			}

	}



	if(arg=="all")

	{

		inv = all_inventory(me);

		for(i=0; i<sizeof(inv); i++)

		{

			do_drop(me, inv[i]);

		}

		write("Ok.\n");

		return 1;

	}



	if(!objectp(obj = present(arg, me)))

		return notify_fail("������û������������\n");

	return do_drop(me, obj);

}



int do_drop(object me, object obj)

{

	mixed no_drop;

	object obj2, * inv;



	if( no_drop = obj->query("no_drop") )

		return notify_fail( stringp(no_drop) ? no_drop : "���������������ⶪ����\n");

	// add by hello 1996.12.02

	// to fix the bug: drop a object like coin many times then the system down.



	if (obj->query_amount() && objectp(obj2=present(obj->query("id"),environment(me))) )

	{

		obj2->set_amount( (int)obj2->query_amount() + (int)obj->query_amount() );

		message_vision( sprintf("$N����һ%s$n��\n", obj->query("unit")),me, obj );

		if( (!obj->query("value") && !obj->value()))

		{

			write("��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ��ڡ�\n");

		}

		if ( wizardp(me) || wizhood(me) == "(immortal)" )

		{

			log_file("static/wizdrop", sprintf("%s%s drop %d %s %s (%s)\n",

				me->query("name"),

				"(" + me->query("id") + ")" ,

				!obj->query_amount()?1:(int)obj->query_amount(),

				obj->query("unit"),

				base_name(obj) + ".c",

				ctime(time())

				) );

		}

		destruct(obj);

		return 1;

	}

	else

	{

		// add by hello 1996.12.3

		// Donnot let the user drop more than 50 things to room.

		inv = all_inventory(environment(me));  

		if (sizeof(inv)>49)

		{

			return notify_fail("�����Ѿ���ô�ණ���ˣ�������\n");

		}



		if (obj->move(environment(me)))

		{

			if ( wizardp(me) || wizhood(me) == "(immortal)" )

			{

				log_file("static/wizdrop", sprintf("%s%s drop %d %s %s (%s)\n",

					me->query("name"),

					"(" + me->query("id") + ")" ,

					!obj->query_amount()?1:(int)obj->query_amount(),

					obj->query("unit"),

					base_name(obj) + ".c",

					ctime(time())

				) );

			}

			if( obj->is_character() )

				message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);

			else

			{

				message_vision( sprintf("$N����һ%s$n��\n", obj->query("unit")), me, obj );

				if( (!obj->query("value") && !obj->value()))

				{

					write("��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ��ڡ�\n");

					destruct(obj);

				}

			}

			return 1;

		}

	}

	return 0;

}



int help(object me)

{

    write(@HELP

ָ���ʽ : drop <��Ʒ����>

 

���ָ��������㶪������Я������Ʒ.

 

HELP

    );

    return 1;

}

 

