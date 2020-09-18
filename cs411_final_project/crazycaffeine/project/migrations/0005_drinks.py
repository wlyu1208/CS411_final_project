# Generated by Django 3.0.4 on 2020-04-09 05:25

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
        ('project', '0004_delete_drinks'),
    ]

    operations = [
        migrations.CreateModel(
            name='Drinks',
            fields=[
                ('drink_name', models.CharField(max_length=30, primary_key=True, serialize=False)),
                ('fl_oz', models.FloatField(blank=True, null=True)),
                ('g_sugar', models.FloatField(blank=True, null=True)),
                ('g_floz', models.FloatField(blank=True, null=True)),
                ('mg_caffeine', models.FloatField(blank=True, null=True)),
                ('mg_floz', models.FloatField(blank=True, null=True)),
            ],
            options={
                'db_table': 'Drinks',
                'managed': False,
            },
        ),
    ]
