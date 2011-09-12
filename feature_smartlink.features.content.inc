<?php

/**
 * Implementation of hook_content_default_fields().
 */
function feature_smartlink_content_default_fields() {
  $fields = array();

  // Exported field: field_smartlink_fields
  $fields['smartlink-field_smartlink_fields'] = array(
    'field_name' => 'field_smartlink_fields',
    'type_name' => 'smartlink',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'mobile' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'smartlink',
    'required' => '0',
    'multiple' => '1',
    'module' => 'smartlink',
    'active' => '1',
    'ctypes' => array(
      'business_profile' => 'business_profile',
      'personal_profile' => 'personal_profile',
    ),
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'field_name' => '',
          'operator' => '',
          'value' => '',
          'percentage' => '100',
          'required' => 0,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Smartlink Fields',
      'weight' => '-3',
      'description' => '',
      'type' => 'smartlink',
      'module' => 'smartlink',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Smartlink Fields');

  return $fields;
}
