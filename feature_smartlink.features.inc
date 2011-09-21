<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function feature_smartlink_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
}

/**
 * Implementation of hook_node_info().
 */
function feature_smartlink_node_info() {
  $items = array(
    'smartlink' => array(
      'name' => t('Smartlink'),
      'module' => 'features',
      'description' => t('A smartlink for creating targeted invites.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_rules_defaults().
 */
function feature_smartlink_rules_defaults() {
  return array(
    'rules' => array(
      'rules_smartlink_rule_user_completes_smartlink' => array(
        '#type' => 'rule',
        '#set' => 'event_smartlink_user_update',
        '#label' => 'Notify inviter when invitee completes smartlink',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'smartlink',
          'feature_smartlink' => 'feature_smartlink',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Smartlink score comparison',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Smartlink node',
                ),
                'user' => array(
                  'type' => 'user',
                  'label' => 'User',
                ),
              ),
              'module' => 'Smartlink',
            ),
            '#name' => 'smartlink_condition_score',
            '#settings' => array(
              'operation' => 'equal',
              'score' => '100',
              '#argument map' => array(
                'node' => 'node',
                'user' => 'user',
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'severity' => '5',
              'type' => 'smartlink',
              'message' => 'Score=100 for [user:user] and smartlink [node:nid]',
              'link' => '',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'type' => array(
                    '0' => ':global',
                  ),
                  'message' => array(
                    '0' => 'node',
                    '1' => 'user',
                    '2' => ':global',
                  ),
                  'link' => array(
                    '0' => ':global',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_watchdog',
            '#info' => array(
              'label' => 'Log to watchdog',
              'module' => 'System',
              'eval input' => array(
                '0' => 'type',
                '1' => 'message',
                '2' => 'link',
              ),
            ),
            '#weight' => 0,
          ),
          '1' => array(
            '#weight' => 0,
            '#type' => 'action',
            '#settings' => array(
              'to' => '[node:author-mail]',
              'from' => '',
              'subject' => '[ApplyRapid] User [user:user] completed your smartlink [node:title]',
              'message' => 'Dear [node:author-name],

Your smartlink [node:title] has been completed by [user:user].

Please go to the report at http://www.applyrapid.com/node/[node:nid]/report.

---
The ApplyRapid Team',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'subject' => array(
                    '0' => 'node',
                    '1' => 'user',
                  ),
                  'message' => array(
                    '0' => 'node',
                    '1' => 'user',
                  ),
                  'to' => array(
                    '0' => 'node',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_mail',
            '#info' => array(
              'label' => 'Send a mail to the smartlink creator',
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
      'rules_smartlink_rule_user_invited' => array(
        '#type' => 'rule',
        '#set' => 'event_smartlink_user_invited',
        '#label' => 'User has been invited to smartlink',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'smartlink',
          'feature_smartlink' => 'feature_smartlink',
        ),
        '#status' => 'default',
        '#conditions' => array(),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Send a mail to a user',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'Recipient',
                ),
              ),
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#name' => 'rules_action_mail_to_user',
            '#settings' => array(
              'from' => '',
              'subject' => '[ApplyRapid] You have been invited for [node:title]',
              'message' => 'Dear [user:user],

You have been invited to apply for [node:title].

Please go to http://www.applyrapid.com/node/[node:nid]/apply.

---
The ApplyRapid.com Team',
              '#argument map' => array(
                'user' => 'user',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'subject' => array(
                    '0' => 'node',
                  ),
                  'message' => array(
                    '0' => 'node',
                    '1' => 'user',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
          '1' => array(
            '#info' => array(
              'label' => 'Log to watchdog',
              'module' => 'System',
              'eval input' => array(
                '0' => 'type',
                '1' => 'message',
                '2' => 'link',
              ),
            ),
            '#name' => 'rules_action_watchdog',
            '#settings' => array(
              'severity' => '5',
              'type' => 'smartlink',
              'message' => 'Smartlink [node:nid] invitation sent to [user:user]',
              'link' => '',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'message' => array(
                    '0' => 'node',
                    '1' => 'user',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'rules_set_invite_field_for_user_smartlink' => array(
        '#type' => 'rule',
        '#set' => 'rules_smartlink_ruleset_invite_user',
        '#label' => 'Set invite field for user smartlink',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          'feature_smartlink' => 'feature_smartlink',
        ),
        '#status' => 'default',
        '#conditions' => array(),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Invite user to given smartlink',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User',
                ),
              ),
              'module' => 'Smartlink',
              'eval input' => array(
                '0' => 'smartlink',
              ),
            ),
            '#name' => 'smartlink_action_invite_user_smartlink',
            '#settings' => array(
              'smartlink' => '<?php echo arg(1) ?>',
              '#argument map' => array(
                'user' => 'user',
              ),
              '#eval input' => array(
                'rules_input_evaluator_php' => array(
                  'smartlink' => array(),
                ),
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
    ),
    'rule_sets' => array(
      'rules_smartlink_ruleset_invite_user' => array(
        'arguments' => array(
          'user' => array(
            'label' => 'User',
            'type' => 'user',
          ),
        ),
        'label' => 'Invite user to apply for smartlink',
        'status' => 'default',
        'categories' => array(
          '0' => 'smartlink',
          'feature_smartlink' => 'feature_smartlink',
        ),
      ),
    ),
  );
}

/**
 * Implementation of hook_views_api().
 */
function feature_smartlink_views_api() {
  return array(
    'api' => '2',
  );
}
