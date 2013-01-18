<?php

/**
 * Helper to implementation of hook_rules_defaults().
 */
function _transition_alert_web_contacts_rules_defaults() {
  return array(
    'rules' => array(
      'transition_alert_web_contacts_1' => array(
        '#type' => 'rule',
        '#set' => 'event_node_insert',
        '#label' => 'Transition - alert web contact of ability to update profile (on create)',
        '#active' => 1,
        '#weight' => '10',
        '#categories' => array(
          'transition_alert_web_contacts' => 'transition_alert_web_contacts',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#negate' => 1,
            '#weight' => 0,
            '#type' => 'condition',
            '#settings' => array(
              'field_name' => 'field_webcontact_user',
              '#argument map' => array(
                'node' => 'node',
              ),
              'value' => array(
                '0' => array(
                  'uid' => NULL,
                ),
              ),
              'code' => '',
              'vars' => array(),
            ),
            '#name' => 'content_rules_field_has_value',
            '#info' => array(
              'label' => 'Web contact field has been specified',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'eval input' => array(
                '0' => 'code',
              ),
              'module' => 'CCK',
            ),
          ),
          '1' => array(
            '#info' => array(
              'label' => 'Initiative profile gets created',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'initiative_profile' => 'initiative_profile',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#type' => 'action',
            '#settings' => array(
              'field' => 'field_webcontact_user',
              '#argument map' => array(
                'node' => 'node',
                'referenced_user' => 'referenced_user',
              ),
            ),
            '#name' => 'userreference_rules_action_load',
            '#info' => array(
              'label' => 'Get the web contact\'s details',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content containing the user reference field',
                ),
              ),
              'new variables' => array(
                'referenced_user' => array(
                  'type' => 'user',
                  'label' => 'Referenced user',
                ),
              ),
              'module' => 'CCK',
            ),
          ),
          '1' => array(
            '#type' => 'action',
            '#settings' => array(
              'to' => '[referenced_user:mail]',
              'from' => '',
              'subject' => 'You now have the ability to update the transition initiative profile "[node:title]"',
              'message' => 'You are the web contact for  "[node:title]" and can now update the profile at [node:node-url]',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'subject' => array(
                    '0' => 'node',
                  ),
                  'message' => array(
                    '0' => 'node',
                  ),
                  'to' => array(
                    '0' => 'referenced_user',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_mail',
            '#info' => array(
              'label' => 'Send a mail to the web contact',
              'label callback' => FALSE,
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
                '3' => 'to',
              ),
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'transition_alert_web_contacts_2' => array(
        '#type' => 'rule',
        '#set' => 'event_node_update',
        '#label' => 'Transition - alert web contact of ability to update profile (on update)',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          'transition_alert_web_contacts' => 'transition_alert_web_contacts',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Updated content is Initiative Profile',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'initiative_profile' => 'initiative_profile',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
          '1' => array(
            '#weight' => 0,
            '#type' => 'condition',
            '#settings' => array(
              'field_name' => 'field_webcontact_user',
              '#argument map' => array(
                'node' => 'node',
                'node_unchanged' => 'node_unchanged',
              ),
            ),
            '#name' => 'content_rules_field_changed',
            '#info' => array(
              'label' => 'Web contact field have changed',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content containing changes',
                ),
                'node_unchanged' => array(
                  'type' => 'node',
                  'label' => 'Content not containing changes',
                ),
              ),
              'module' => 'CCK',
            ),
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#info' => array(
              'label' => 'Get the web contact\'s details',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content containing the user reference field',
                ),
              ),
              'new variables' => array(
                'referenced_user' => array(
                  'type' => 'user',
                  'label' => 'Referenced user',
                ),
              ),
              'module' => 'CCK',
            ),
            '#name' => 'userreference_rules_action_load',
            '#settings' => array(
              'field' => 'field_webcontact_user',
              '#argument map' => array(
                'node' => 'node',
                'referenced_user' => 'referenced_user',
              ),
            ),
            '#type' => 'action',
            '#weight' => 0,
          ),
          '1' => array(
            '#weight' => 0,
            '#type' => 'action',
            '#settings' => array(
              'to' => '[referenced_user:mail]',
              'from' => '',
              'subject' => 'You now have the ability to update the transition initiative profile "[node:title]"',
              'message' => 'You are the web contact for  "[node:title]" and can now update the profile at [node:node-url]',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'subject' => array(
                    '0' => 'node',
                  ),
                  'to' => array(
                    '0' => 'referenced_user',
                  ),
                  'message' => array(
                    '0' => 'node',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_mail',
            '#info' => array(
              'label' => 'Send a mail to the web contact',
              'label callback' => FALSE,
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
                '3' => 'to',
              ),
            ),
          ),
        ),
        '#version' => 6003,
      ),
    ),
  );
}
