<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function feature_smartlink_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'smartlink_application';
  $context->description = 'Smartlink application';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*/apply' => 'node/*/apply',
        'node/*/apply/*' => 'node/*/apply/*',
        'node/*/apply/*/*' => 'node/*/apply/*/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'smartlink-smartlink_user' => array(
          'module' => 'smartlink',
          'delta' => 'smartlink_user',
          'region' => 'sidebar_right',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Smartlink application');
  $export['smartlink_application'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'smartlink_node_view';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'smartlink' => 'smartlink',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'smartlink-smartlink_apply' => array(
          'module' => 'smartlink',
          'delta' => 'smartlink_apply',
          'region' => 'sidebar_right',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['smartlink_node_view'] = $context;

  return $export;
}
